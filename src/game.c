/**
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 *
 * @file game.c
 * @version 1.0
 * @author Profesores PPROG
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management.h"

#define N_CALLBACK 16            //The number of callbacks for the commands

 struct _Game{
  Player* player;                        // A pointer to the player of the game
  Object* objects[MAX_OBJECTS + 1];      // An array with all the objects of the game
  Space* spaces[MAX_SPACES + 1];         // An array with all the spaces of the game
  Die* die;                              // A pointer to the die of the game
  T_Command last_cmd;                    // The last command executed in a game
  STATUS last_cmd_status;                // The status of the last command executed in a game
  Link* links[MAX_LINKS + 1];            // An array with all the links between spaces in the game
  char last_desc[WORD_SIZE + 1];         // The last description looked up by the player
};

/**
   Define the function type for the callbacks
*/
typedef STATUS (*callback_fn)(Game game);

/**
   List of callbacks for each command in the game
*/
STATUS game_callback_unknown(Game game);   //A callback for the UNKNOWN command
STATUS game_callback_exit(Game game);      //A callback for the EXIT command
STATUS game_callback_next(Game game);      //A callback for the NEXT command
STATUS game_callback_back(Game game);      //A callback for the BACK command
STATUS game_callback_take(Game game);      //A callback for the TAKE command
STATUS game_callback_drop(Game game);      //A callback for the DROP command
STATUS game_callback_roll(Game game);      //A callback for the ROLL command
STATUS game_callback_left(Game game);      //A callback for the LEFT command
STATUS game_callback_right(Game game);     //A callback for the RIGHT command
STATUS game_callback_move(Game game);      //A callback for the MOVE command
STATUS game_callback_inspect(Game game);   //A callback for the INSPECT command
STATUS game_callback_turnon(Game game);    //A callback for the TURNON command
STATUS game_callback_turnoff(Game game);   //A callback for the TURNOFF command
STATUS game_callback_open(Game game);      //A callback for the OPEN command
STATUS game_callback_save(Game game);      //A callback for the SAVE command
STATUS game_callback_load(Game game);      //A callback for the LOAD command


static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back,
  game_callback_take,
  game_callback_drop,
  game_callback_roll,
  game_callback_left,
  game_callback_right,
  game_callback_move,
  game_callback_inspect,
  game_callback_turnon,
  game_callback_turnoff,
  game_callback_open,
  game_callback_save,
  game_callback_load};

/**
   Define the function type for the directions
*/
typedef Id (*direction_fn)(Space* space);

/**
   List of geters for each direction in a space
*/
static direction_fn space_direction_fn_list[4]={
  space_get_north,
  space_get_south,
  space_get_east,
  space_get_west};

/**
   Private functions
*/

/**
 * @brief Gets a space from a game
 *
 * Gets an index as input and returns the space that is in that position in the spaces[]
 * matrix in the game
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct from which the space will be returned
 * @param position the position of the space in the spaces[] matrix in the game
 * @return the id of that space
 */
Id game_get_space_id_at(Game game, int position);

/**
 * @brief Gets a objects from a game
 *
 * Gets an index as input and returns the objects that is in that position in the objects[]
 * matrix in the game
 *
 * @author Evangelos Lazarakis
 * @date 03-03-2020
 *
 * @param game the game struct from which the objects will be returned
 * @param position the position of the objects in the objects[] matrix in the game
 * @return the id of that objects
 */
Id game_get_object_id_at(Game game, int position);

/**
 * @brief Sets the player's location Id in a game
 *
 * Gets a game and an Id as input and sets it as the player's locations
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param game the game struct in which the player location Id is going to change
 * @param id the Id of the space that the player is located
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_set_player_location(Game game, Id id);

/**
 * @brief Sets an object's location in a game
 *
 * Gets a space Id and an object Id and adds the later
 * in the space's set of objects
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param game the game struct in which the object location Id is going to change
 * @param object_id the Id of the object whose location we want to set
 * @param space_id the Id of the space in which we want to place the object
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_set_object_location(Game game, Id object_id, Id space_id);


/**
   Game interface implementation
*/

Game game_create() {

  Game game = malloc(sizeof(*game));
  int i;

  for (i = 0; i <= MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  for (i = 0; i <= MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }

  for (i = 0; i <= MAX_LINKS; i++) {
    game->links[i] = NULL;
  }

  game->player = NULL;                 //The player is always initialized with the PLAYER_ID
  game->die = die_create(1, 1, 6);     //The die is always initialized with the value 1
  game->last_cmd = NO_CMD;
  game->last_cmd_status = OK;
  game->last_desc[0] = '\0';

  return game;
}

Game game_create_from_file(char* filename) {

  Game game = game_create();
  if (game == NULL)
    return NULL;

  if (game_management_load_spaces(game, filename) == ERROR)
    return NULL;

  if (game_management_load_objects(game, filename) == ERROR)
    return NULL;

  if (game_management_load_links(game, filename) == ERROR)
    return NULL;

  if (game_management_load_players(game, filename) == ERROR)
    return NULL;

  return game;
}

STATUS game_destroy(Game game) {
  int i = 0;

  for (i = 0; game->spaces[i] != NULL; i++) {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; game->objects[i] != NULL; i++) {
    object_destroy(game->objects[i]);
  }

  for (i = 0; game->links[i] != NULL; i++) {
    link_destroy(game->links[i]);
  }

  player_destroy(game->player);

  die_destroy(game->die);

  free(game);

  return OK;
}

Id game_get_space_id_at(Game game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }
  return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}

Player* game_get_player(Game game) {
  return game->player;
}

Die* game_get_die(Game game) {
  return game->die;
}

Object* game_get_object(Game game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; game->objects[i] != NULL; i++) {
    if (id == object_get_id(game->objects[i])){
      return game->objects[i];
    }
  }

  return NULL;
}

Object* game_get_object_at(Game game, int position) {
  if (position < 0 || position >= MAX_OBJECTS) {
    return NULL;
  }

  return game->objects[position];
}

Space* game_get_space_at(Game game, int position) {
  if (position < 0 || position >= MAX_SPACES) {
    return NULL;
  }

  return game->spaces[position];
}

STATUS game_add_player(Game game, Player* player) {
  if(player == NULL) {
    return ERROR;
  }

  game->player = player;

  return OK;
}

STATUS game_set_player_location(Game game, Id id) {

  if (id == NO_ID) {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;

}

STATUS game_set_object_location(Game game, Id object_id, Id space_id) {

  if (object_id == NO_ID) {
    return ERROR;
  }

  if (space_id == NO_ID) {
    return ERROR;
  }

  if(!space_add_object(game_get_space(game,space_id), object_id)){
    return OK;
  }

  return ERROR;
}

Id game_get_player_location(Game game) {
  return player_get_location(game->player);
}

Id game_get_object_location(Game game, Id object_id) {

  int i;

  for(i=0; game->spaces[i] != NULL; i++){                           //Goes through the spaces[] matrix of the game until it finds the space,
    if(space_contain_object(game->spaces[i], object_id) == TRUE)    //which contains the object we are looking for, and return its id
      return space_get_id(game->spaces[i]);
  }

  return NO_ID;                                                             //If no such space is found, NO_ID is returned

}

Id game_get_object_id_at(Game game, int position) {

  if (position < 0 || position >= MAX_OBJECTS) {
    return NO_ID;
  }
  return object_get_id(game->objects[position]);
}

int game_get_n_objects(Game game){

  int i = 0;
  while(game->objects[i] != NULL){
    i++;
  }

  return i;
}

int game_get_n_links(Game game){

  int i = 0;
  while(game->links[i] != NULL){
    i++;
  }

  return i;
}

int game_get_n_spaces(Game game) {
  int i = 0;
  while(game->spaces[i] != NULL){
    i++;
  }

  return i;
}

STATUS game_set_last_description(Game game, char* desc) {

  if(desc == NULL) {
    return ERROR;
  }

  strcpy(game->last_desc, desc);

  return OK;
}

char* game_get_last_description(Game game) {
  return game->last_desc;
}

STATUS game_update(Game game, T_Command cmd) {
  game->last_cmd = cmd;
  game->last_cmd_status = (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game game){
  return game->last_cmd;
}

STATUS game_get_last_command_status(Game game){
  return game->last_cmd_status;
}

STATUS game_add_space(Game game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( game->spaces[i] != NULL){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

STATUS game_add_object(Game game, Object* object) {
  int i = 0;

  if (object == NULL) {
    return ERROR;
  }


  while ( game->objects[i] != NULL){
    i++;
  }

  if (i >= MAX_OBJECTS) {
    return ERROR;
  }

  game->objects[i] = object;

  return OK;
}

STATUS game_add_link(Game game, Link* link) {
  int i = 0;

  if (link == NULL) {
    return ERROR;
  }


  while ( game->links[i] != NULL){
    i++;
  }

  if (i >= MAX_LINKS) {
    return ERROR;
  }

  game->links[i] = link;

  return OK;
}

Link* game_get_link(Game game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; game->links[i] != NULL; i++) {
    if (id == link_get_id(game->links[i])){
      return game->links[i];
    }
  }

  return NULL;
}

Link* game_get_link_at(Game game, int position){
  if (position < 0 || position >= MAX_LINKS) {
    return NULL;
  }

  return game->links[position];
}

void game_print_data(Game game) {

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (int i = 0; game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("\n=> Player :\n");
  player_print(game->player);

  printf("\n=> Objects :\n");
  for (int i = 0; game->objects[i] != NULL; i++) {
    object_print(game->objects[i]);
  }

  printf("\n=> Die:  \n");
  die_print(game->die);

  printf("\n=> Links:  \n");
  Link* link = game_get_link(game, 1);
  int i = 1;

  while(link != NULL) {
    link_print(link);
    link = game_get_link(game,++i);
  }

  printf("prompt:> ");
}

BOOL game_is_over(Game game) {
  return FALSE;
}

/**
   Callbacks implementation for each action
*/

STATUS game_callback_unknown(Game game) {
  return OK;
}

STATUS game_callback_exit(Game game) {
  return OK;
}

STATUS game_callback_next(Game game) {
  Space* space = game_get_space(game,game_get_player_location(game));
  Id south = space_get_south(space);

  if(south != NO_ID){
    game_set_player_location(game, link_get_other(game_get_link(game, south), space_get_id(space)));
    return OK;
  } else {
    return ERROR;
  }
}

STATUS game_callback_back(Game game) {
  Space* space = game_get_space(game,game_get_player_location(game));
  Id north = space_get_north(space);

  if(north != NO_ID){
    game_set_player_location(game, link_get_other(game_get_link(game, north), space_get_id(space)));
    return OK;
  } else {
    return ERROR;
  }
}

STATUS game_callback_take(Game game){

  Space* space = game_get_space(game,game_get_player_location(game));

  char obj[255];
  scanf("%s",obj);      // The object's name must be typed in order to take it from a space

  int n_objects = game_get_n_objects(game);

  if(player_backpack_has_space(game->player) == OK){
    for(int i = 0; i < n_objects; i++){
      Id obj_id = object_get_id(game->objects[i]);
      if (game_get_object_location(game, obj_id) == space_get_id(space)){
        if (strcmp(obj, object_get_name(game->objects[i])) == 0){
          player_add_object(game->player, obj_id);
          space_del_object(space, obj_id);
          return OK;
        }
      }
    }
  }

  return ERROR;
}

STATUS game_callback_drop(Game game){

  Space* space = game_get_space(game,game_get_player_location(game));

  char obj[255];
  scanf("%s",obj);      // The object's name must be typed in order to drop it

  int n_objects = game_get_n_objects(game);

  for(int i = 0; i < n_objects; i++) {
    Object* dummy = game_get_object_at(game, i);
    if (strcmp(obj, object_get_name(dummy)) == 0) {
      Id obj_id = object_get_id(dummy);
      if (player_search_object(game->player, obj_id) != NO_ID) {
        player_del_object(game->player, obj_id);
        space_add_object(space, obj_id);
        return OK;
      }
    }
  }

  return ERROR;

}

STATUS game_callback_roll(Game game){
  die_roll(game->die);
  return OK;
}

STATUS game_callback_left(Game game){

  Space* space = game_get_space(game,game_get_player_location(game));
  Id west = space_get_west(space);

  if(west != NO_ID){
    game_set_player_location(game, link_get_other(game_get_link(game, west), space_get_id(space)));
    return OK;
  } else {
    return ERROR;
  }
}

STATUS game_callback_right(Game game){

  Space* space = game_get_space(game,game_get_player_location(game));
  Id east = space_get_east(space);

  if(east != NO_ID){
    game_set_player_location(game, link_get_other(game_get_link(game, east), space_get_id(space)));
    return OK;
  } else {
    return ERROR;
  }
}

STATUS game_callback_move(Game game) {

  Space* space = game_get_space(game,game_get_player_location(game));

  char dir[255];      // The direction of the move command
  scanf("%s",dir);
  DIRECTION d;

  if((strcmp(dir, "n") == 0) || (strcmp(dir, "north") == 0)) {
    d = N;
  } else if((strcmp(dir, "e") == 0) || (strcmp(dir, "east") == 0)) {
    d = E;
  } else if((strcmp(dir, "s") == 0) || (strcmp(dir, "south") == 0)) {
    d = S;
  } else if((strcmp(dir, "w") == 0) || (strcmp(dir, "west") == 0)) {
    d = W;
  } else {return ERROR;}

  Id direction = (*space_direction_fn_list[d])(space);

  if(direction != NO_ID){
    Link* link = game_get_link(game, direction);
    if(link_get_status(link) == OP){
      game_set_player_location(game, link_get_other(game_get_link(game, direction), space_get_id(space)));
      return OK;
    }
  }

  return ERROR;
}

STATUS game_callback_inspect(Game game) {

  Space* space = game_get_space(game,game_get_player_location(game));

  char target[255];      // The target of the inspect command
  scanf("%s",target);

  if((strcmp(target, "s") == 0) || (strcmp(target, "space") == 0)) {
    game_set_last_description(game, space_get_description(space));
    return OK;
  } else {
    for(int i = 0; game->objects[i] != NULL; i++){
      if(strcmp(target, object_get_name(game->objects[i])) == 0) {
        Object* obj = game_get_object_at(game, i);
        Id obj_id = object_get_id(obj);
        if((player_search_object(game->player, obj_id) != NO_ID) || (space_contain_object(space, obj_id) == TRUE)) {
          game_set_last_description(game, object_get_description(obj));
          return OK;
        }
      }
    }
  }

  return ERROR;
}

STATUS game_callback_turnon(Game game){
  Id obj_id = NO_ID;
  char target[255];      // The target of the turnon command
  scanf("%s",target);

  for(int i = 0; i < game_get_n_objects(game); i++) {        // Search for the target object in the game
    Object* object = game_get_object_at(game, i);
    if(strcmp(target, object_get_name(object)) == 0) {
      obj_id = object_get_id(object);
    }
  }

  if(obj_id != NO_ID){                                                   // If the object is in the players backpack and can be illuminated
    if(player_search_object(game_get_player(game), obj_id) == obj_id) {  // the object is turned on if it is not already
      Object* object = game_get_object(game, obj_id);
      if((object_get_illuminate(object) == TRUE) && (object_get_turnedon(object) == FALSE)) {
        object_set_turnedon(object, TRUE);
        return OK;
      }
    }
  }

  return ERROR;
}

STATUS game_callback_turnoff(Game game){
  Id obj_id = NO_ID;
  char target[255];      // The target of the turnoff command
  scanf("%s",target);

  for(int i = 0; i < game_get_n_objects(game); i++) {        // Search for the target object in the game
    Object* object = game_get_object_at(game, i);
    if(strcmp(target, object_get_name(object)) == 0) {
      obj_id = object_get_id(object);
    }
  }

  if(obj_id != NO_ID){                                                   // If the object is in the players backpack and can be illuminated
    if(player_search_object(game_get_player(game), obj_id) == obj_id) {  // the object is turned off if it is not already
      Object* object = game_get_object(game, obj_id);
      if((object_get_illuminate(object) == TRUE) && (object_get_turnedon(object) == TRUE)) {
        object_set_turnedon(object, FALSE);
        return OK;
      }
    }
  }

  return ERROR;
}

STATUS game_callback_open(Game game){
  Space* space = game_get_space(game,game_get_player_location(game));

  Id link_id = NO_ID;
  char target_link[255];      // The target link of the open command
  scanf("%s",target_link);

  for(int i = 0; i < game_get_n_links(game); i++) {        // Search for the target link in the game
    Link* link = game_get_link_at(game, i);
    if(strcmp(target_link, link_get_name(link)) == 0) {
      link_id = link_get_id(link);
    }
  }

  char with[255];           // Expecting "with" as input
  scanf("%s",with);

  if((strcmp(with, "with") == 0) && (link_id != NO_ID)){
    Id obj_id = NO_ID;
    char target_obj[255];      // The target object of the open command
    scanf("%s",target_obj);

    for(int i = 0; i < game_get_n_objects(game); i++) {        // Search for the target object in the game
      Object* object = game_get_object_at(game, i);
      if(strcmp(target_obj, object_get_name(object)) == 0) {
        obj_id = object_get_id(object);
      }
    }

    if(obj_id != NO_ID){                                                      // If the object is in the player's backpack and can open the link specified
      if(player_search_object(game_get_player(game), obj_id) == obj_id){      // and the link is on the space that the player is, then the link is opened if
        Object* object = game_get_object(game, obj_id);                       // it is not already
        if(object_get_open(object) == link_id){
          if((link_id == space_get_north(space)) || (link_id == space_get_east(space)) || (link_id == space_get_south(space)) || (link_id == space_get_west(space))) {
            Link* link = game_get_link(game, link_id);
            if(link_get_status(link) == CL) {
              link_set_status(link, OP);
              return OK;
            }
          }
        }
      }
    }
  }

  return ERROR;
}

STATUS game_callback_save(Game game){
  char target[255];      // The target file of the save command
  scanf("%s",target);

  return game_management_save(game, target);
}

STATUS game_callback_load(Game game){
  char target[255];      // The target file of the load command
  scanf("%s",target);

  return game_management_load(game, target);
}
