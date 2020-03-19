/** 
 * @brief It implements the game reader 
 * 
 * @file game_reader.c
 * @author Adam Mahjoub
 * @version 1.0 
 * @date 13-02-2020
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"
#include "game.h"


STATUS game_reader_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
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

STATUS game_reader_load_objects(Game* game, char* filename){

  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
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

    #ifdef DEBUG
      printf("Leido: %ld|%s|%ld|", id, name,location);
    #endif
      
      object = object_create(id);
      if (object != NULL) {
       object_set_name(object, name);
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