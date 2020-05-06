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

      space = game_get_space(game,location);
      space_add_object(space,id);
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
