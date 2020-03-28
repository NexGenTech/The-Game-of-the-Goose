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
#include "game_reader.h"

#define N_CALLBACK 9            //The number of callbacks for the commands
#define PLAYER_ID 24            //This is the player_id that the player is initialized with during the game creation by the game_create function
#define OBJECT_ID 8             //This is the object_id that the object is initialized with during the game creation by the game_create function

/**
   Define the function type for the callbacks
*/
typedef STATUS (*callback_fn)(Game* game);

/**
   List of callbacks for each command in the game
*/
STATUS game_callback_unknown(Game* game);   //A callback for the UNKNOWN command
STATUS game_callback_exit(Game* game);      //A callback for the EXIT command
STATUS game_callback_next(Game* game);      //A callback for the NEXT command
STATUS game_callback_back(Game* game);      //A callback for the BACK command
STATUS game_callback_take(Game* game);      //A callback for the TAKE command
STATUS game_callback_drop(Game* game);      //A callback for the DROP command
STATUS game_callback_roll(Game* game);      //A callback for the ROLL command
STATUS game_callback_left(Game* game);      //A callback for the LEFT command
STATUS game_callback_right(Game* game);     //A callback for the RIGHT command

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back,
  game_callback_take,
  game_callback_drop,
  game_callback_roll,
  game_callback_left,
  game_callback_right};

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
Id game_get_space_id_at(Game* game, int position);

/**
 * @brief Gets a objects from a game
 *
 * Gets an index as input and returns the objects that is in that position in the objectss[]
 * matrix in the game
 *
 * @author Evangelos Lazarakis
 * @date 03-03-2020
 *
 * @param game the game struct from which the objects will be returned
 * @param position the position of the objects in the objectss[] matrix in the game
 * @return the id of that objects
 */
Id game_get_object_id_at(Game* game, int position);

/**
 * @brief Sets the player's location Id in a game
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param game the game struct in which the player location Id is going to change
 * @param id the Id of the space that the player is located
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_set_player_location(Game* game, Id id);

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
STATUS game_set_object_location(Game* game, Id object_id, Id space_id);


/**
   Game interface implementation
*/

STATUS game_create(Game* game) {
  int i;

  for (i = 0; i <= MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  for (i = 0; i <= MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }

  game->player = player_create(PLAYER_ID);              //The player is always initialized with the PLAYER_ID
  game->die = die_create(1);                            //The die is always initialized with the value 1
  game->last_cmd = NO_CMD;
  game->last_cmd_status = OK;

  return OK;
}

STATUS game_create_from_file(Game* game, char* filename) {

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_objects(game, filename) == ERROR)
    return ERROR;

  game_set_player_location(game, game_get_space_id_at(game, 0));

  return OK;
}

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; game->spaces[i] != NULL; i++) {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; game->objects[i] != NULL; i++) {
    object_destroy(game->objects[i]);
  }

  player_destroy(game->player);

  die_destroy(game->die);

  return OK;
}

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }
  return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id){
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

Player* game_get_player(Game* game) {
  return game->player;
}

Die* game_get_die(Game* game) {
  return game->die;
}

Object* game_get_object(Game* game, Id id){
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

Object* game_get_object_at(Game* game, int pos) {

  if (position < 0 || position >= MAX_SPACES) {
    return NULL;
  }

  return game->objects[pos];
}

STATUS game_set_player_location(Game* game, Id id) {

  if (id == NO_ID) {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;

}

STATUS game_set_object_location(Game* game, Id object_id, Id space_id) {

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

Id game_get_player_location(Game* game) {
  return player_get_location(game->player);
}

Id game_get_object_location(Game* game, Id object_id) {

  int i;

  for(i=0; game->spaces[i] != NULL; i++){                           //Goes through the spaces[] matrix of the game until it finds the space,
    if(space_contain_object(game->spaces[i], object_id) == TRUE)    //which contains the object we are looking for, and return its id
      return space_get_id(game->spaces[i]);
  }

  return NO_ID;                                                             //If no such space is found, NO_ID is returned

}

Id game_get_object_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_OBJECTS) {
    return NO_ID;
  }
  return object_get_id(game->objects[position]);
}

int game_get_n_objects(Game* game){

  int i = 0;
  while(game->objects[i] != NULL){
    i++;
  }

  return i;
}

STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  game->last_cmd_status = (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

STATUS game_get_last_command_status(Game* game){
  return game->last_cmd_status;
}

STATUS game_add_space(Game* game, Space* space) {
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

STATUS game_add_object(Game* game, Object* object) {
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

void game_print_data(Game* game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Player :\n");
  player_print(game->player);

  printf("=> Objects :\n");
  for (i = 0; game->objects[i] != NULL; i++) {
    object_print(game->objects[i]);
  }

  printf("=> Die:  ");

  die_print(game->die);
  printf("prompt:> ");
}

BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Callbacks implementation for each action
*/

STATUS game_callback_unknown(Game* game) {
  return OK;
}

STATUS game_callback_exit(Game* game) {
  return OK;
}

STATUS game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  for (i = 0; game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
         game_set_player_location(game, current_id);
         return OK;
      } else {
        return ERROR;
      }
    }
  }

  return ERROR;
}

STATUS game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  for (i = 0; game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
        game_set_player_location(game, current_id);
        return OK;
      } else{
        return ERROR;
      }
    }
  }

  return ERROR;
}

STATUS game_callback_take(Game* game){

  Space* space = game_get_space(game,game_get_player_location(game));

  char obj[255];
  scanf("%s",obj);      // The object's name must be typed in order to take it from a space

  int n_objects = game_get_n_objects(game);

  if(player_get_object(game->player) == NO_ID){
    for(int i = 0; i < n_objects; i++){
      Id obj_id = object_get_id(game->objects[i]);
      if (game_get_object_location(game, obj_id) == space_get_id(space)){
        if(strcmp(obj, object_get_name(game->objects[i])) == 0){
          player_set_object(game->player, obj_id);
          space_del_object(space, obj_id);
          return OK;
        }
      }
    }
  }

  return ERROR;
}

STATUS game_callback_drop(Game* game){

  Space* space = game_get_space(game,game_get_player_location(game));

  if(player_get_object(game->player) != NO_ID){
    game_set_object_location(game, player_get_object(game->player) ,space_get_id(space));
    player_set_object(game->player,NO_ID);
    return OK;
  } else {
    return ERROR;
  }

}

STATUS game_callback_roll(Game* game){
  die_roll(game->die);
  return OK;
}

STATUS game_callback_left(Game* game){

  Space* space = game_get_space(game,game_get_player_location(game));
  Id west = space_get_west(space);

  if(west != NO_ID){
    game_set_player_location(game, west);
    return OK;
  } else {
    return ERROR;
  }
}

STATUS game_callback_right(Game* game){

  Space* space = game_get_space(game,game_get_player_location(game));
  Id east = space_get_east(space);

  if(east != NO_ID){
    game_set_player_location(game, east);
    return OK;
  } else {
    return ERROR;
  }
}
