/**
 * @brief It implements the game management
 *
 * @file game_management.c
 * @author Adam Mahjoub
 * @version 1.0
 * @date 13-02-2020
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management.h"
#include "game.h"


STATUS game_management_load_spaces(Game game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  char line1[WORD_SIZE] = "";
  char line2[WORD_SIZE] = "";
  char line3[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(line1, toks);
      toks = strtok(NULL, "|");
      strcpy(line2, toks);
      toks = strtok(NULL, "|");
      strcpy(line3, toks);
      toks = strtok(NULL, "|");
      strcpy(desc, toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif

      space = space_create(id);
      if (space != NULL) {
       space_set_name(space, name);
       space_set_north(space, north);
       space_set_east(space, east);
       space_set_south(space, south);
       space_set_west(space, west);
       space_set_graphics_line(space, line1, 0);
       space_set_graphics_line(space, line2, 1);
       space_set_graphics_line(space, line3, 2);
       space_set_description(space, desc);
       game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_load_objects(Game game, char* filename){

  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object* object = NULL;
  Space* space = NULL;
  STATUS status = OK;


  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(desc, toks);

    #ifdef DEBUG
      printf("Leido: %ld|%s|%ld|", id, name,location);
    #endif

      object = object_create(id);
      if (object != NULL) {
       object_set_name(object, name);
       object_set_description(object, desc);
       game_add_object(game, object);
      }

      if(location != NO_ID){
        space = game_get_space(game,location);
        space_add_object(space,id);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;

}

STATUS game_management_load_players(Game game, char* filename) {

  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, location = NO_ID;
  int backpack_size = 0;
  Player* player = NULL;
  STATUS status = OK;


  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#p:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      backpack_size = atoi(toks);

      player = player_create(id);
      if (player != NULL) {
        player_set_name(player, name);
        player_set_backpack_size(player, backpack_size);
        player_set_location(player, location);
      }

      game_add_player(game, player);
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_load_links(Game game, char* filename) {

  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, space_one = NO_ID, space_two = NO_ID;
  LINK_STATUS link_status = OP;
  Link* link = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#l:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space_one = atol(toks);
      toks = strtok(NULL, "|");
      space_two = atol(toks);
      toks = strtok(NULL, "|");
      link_status = atol(toks);

      link = link_create(id);
      if (link != NULL) {
        link_set_name(link, name);
        link_set_space_one_id(link, space_one);
        link_set_space_two_id(link, space_two);
        link_set_status(link, link_status);
        game_add_link(game, link);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_save(Game game, char* filename){
  FILE* file = NULL;
  Player* player = NULL;
  Space* space = NULL;
  Object* object = NULL;
  Link* link = NULL;
  char str[255];

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "w");
  if (file == NULL) {
    return ERROR;
  }

  // Save the game's spaces
  for(int i = 0; i < game_get_n_spaces(game); i++) {
    space = game_get_space_at(game, i);

    sprintf(str, "#s:%ld|%s|%ld|%ld|%ld|%ld|%s|%s|%s|%s|\n", space_get_id(space), space_get_name(space), space_get_north(space), space_get_east(space),
    space_get_south(space), space_get_west(space), space_get_graphics_line(space, 0), space_get_graphics_line(space, 1), space_get_graphics_line(space, 2),
    space_get_description(space));

    fprintf(file,"%s", str);
  }

  // Save the game's objects
  for(int i = 0; i < game_get_n_objects(game); i++) {
    object = game_get_object_at(game, i);

    sprintf(str, "#o:%ld|%s|%ld|%s|\n", object_get_id(object), object_get_name(object), game_get_object_location(game, object_get_id(object)), object_get_description(object));

    fprintf(file, "%s",str);
  }

  // Save the game's links
  for(int i = 0; i < game_get_n_links(game); i++) {
    link = game_get_link_at(game, i);

    sprintf(str, "#l:%ld|%s|%ld|%ld|%d|\n", link_get_id(link), link_get_name(link), link_get_space_one_id(link), link_get_space_two_id(link), link_get_status(link));

    fprintf(file, "%s", str);
  }

  // Save the game's player
  player = game_get_player(game);
  sprintf(str, "#p:%ld|%s|%ld|%d|", player_get_id(player), player_get_name(player), player_get_location(player), player_get_backpack_size(player));
  fprintf(file, "%s", str);

  fclose(file);

  return OK;

}

STATUS game_management_load(Game game, char* filename){
  if (!filename) {
    return ERROR;
  }

  if(!game_destroy(game)){
    return ERROR;
  }

  game = game_create_from_file(filename);

  if(game == NULL){
    return ERROR;
  }

  for(int i = 0; i < game_get_n_objects(game); i++) {
    Object* object = game_get_object_at(game, i);
    Id obj_id = object_get_id(object);

    if(game_get_object_location(game, obj_id) == NO_ID){
      player_add_object(game_get_player(game), obj_id);
    }
  }

  return OK;
}
