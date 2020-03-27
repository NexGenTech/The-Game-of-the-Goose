/**
 * @brief It implements the space functions
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"



typedef struct _Space{
  Id id;                      // Id of the space
  char name[WORD_SIZE + 1];   // The name of the space
  Id north;                   // The Id of the space that this is linked in the north
  Id south;                   // The Id of the space that this is linked in the south
  Id east;                    // The Id of the space that this is linked in the east
  Id west;                    // The Id of the space that this is linked in the west
  Set* objects;               // The set of the Id's of the objects that are on this space
  char gdesc[3][8];           // An array of characters that hold the graphic description of the space
}Space;



Space* space_create(Id id) {

  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));

  if (newSpace == NULL) {
    return NULL;
  }

  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->objects = set_create();

  int i;
  for(i=0 ; i<3 ; i++){
    newSpace->gdesc[i][0] = '\0';
  }

  return newSpace;
}

STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  free(space->objects);
  free(space);
  space = NULL;

  return OK;
}

STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

STATUS space_add_object(Space* space, Id object) {
  if (!space) {
    return ERROR;
  }

  if(!set_add(space->objects, object)){
    return ERROR;
  }

  return OK;
}

STATUS space_del_object(Space* space, Id object){

  if (!space) {
    return ERROR;
  }

  if(!set_del(space->objects, object)){
    return ERROR;
  }

  return OK;

}

STATUS space_set_graphics_line(Space* space, char* graphics, int line){

  if (!space || !graphics) {
    return ERROR;
  }

  if(!strcpy(space->gdesc[line],graphics)){
    return ERROR;
  }

  return OK;
}

const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

BOOL space_contain_object(Space* space, Id id) {

  if(set_search_id(space->objects, id) == NO_ID){
    return FALSE;
  }

  return TRUE;
}

Id space_get_id_at(Space* space, int position){

  if (position < 0 || position >= MAX_CAPACITY) {
    return NO_ID;
  }

  return set_get_id_at(space->objects, position);
}

int space_get_n_objects(Space* space){
  return set_get_n_ids(space->objects);
}

char* space_get_graphics_line(Space* space, int line){
  return space->gdesc[line];
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;    // idaux is going to help with the printing by loading into it every field if the space

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  int n_objects = space_get_n_objects(space);
  if(n_objects != 0){
    fprintf(stdout, "---> Objects :\n");
    for(int i = 0; i < n_objects ; i++){
      printf("\t%ld\n",set_get_id_at(space->objects,i));
    }
  } else {
    fprintf(stdout, "---> No objects in the space.\n");
  }

  fprintf(stdout, "---> Graphic Description :\n");
  for(int i = 0; i <= 2; i++){
    printf("\t%s\n",space_get_graphics_line(space,i));
  }

  return OK;
}
