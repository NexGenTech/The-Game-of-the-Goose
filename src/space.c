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
  Id id;                                // Id of the space
  char name[WORD_SIZE + 1];             // The name of the space
  Id north;                             // The Id of the space that this is linked in the north
  Id south;                             // The Id of the space that this is linked in the south
  Id east;                              // The Id of the space that this is linked in the east
  Id west;                              // The Id of the space that this is linked in the west
  Id up;                                // The Id of the space that this is linked in the above floor
  Id down;                              // The Id of the space that this is linked in the below floor
  Set* objects;                         // The set of the Id's of the objects that are on this space
  char gdesc[3][8];                     // An array of characters that hold the graphic description of the space
  char description[WORD_SIZE + 1];      // A description of the space
  char det_description[WORD_SIZE + 1];  // A more detailed description of the space
  BOOL illuminate;                      // Specifies if a space is illuminated or not
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
  newSpace->up = NO_ID;
  newSpace->down = NO_ID;

  newSpace->objects = set_create();

  for(int i=0 ; i<3 ; i++){
    newSpace->gdesc[i][0] = '\0';
  }

  newSpace->description[0] = '\0';
  newSpace->det_description[0] = '\0';

  newSpace->illuminate = FALSE;

  return newSpace;
}

STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  set_destroy(space->objects);
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
  if (!space) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

STATUS space_set_south(Space* space, Id id) {
  if (!space) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

STATUS space_set_east(Space* space, Id id) {
  if (!space) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

STATUS space_set_west(Space* space, Id id) {
  if (!space) {
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

STATUS space_set_description(Space* space, char* desc) {

  if(desc == NULL) {
    return ERROR;
  }

  strcpy(space->description, desc);

  return OK;
}

char* space_get_description(Space* space) {
  return space->description;
}

STATUS space_set_det_description(Space* space, char* desc) {

  if(desc == NULL) {
    return ERROR;
  }

  strcpy(space->det_description, desc);

  return OK;
}

char* space_get_det_description(Space* space) {
  return space->det_description;
}

STATUS space_set_illuminate(Space* space, BOOL illuminate) {
  if (!space || !illuminate) {
    return ERROR;
  }

  space->illuminate = illuminate;

  return OK;
}

BOOL space_get_illuminate(Space* space) {
  if (!space) {
    return FALSE;
  }
  return space->illuminate;
}

STATUS space_set_up(Space* space, Id id) {
  if (!space) {
    return ERROR;
  }
  space->up = id;
  return OK;
}

Id space_get_up(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->up;
}

STATUS space_set_down(Space* space, Id id) {
  if (!space) {
    return ERROR;
  }
  space->down = id;
  return OK;
}

Id space_get_down(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->down;
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;    // idaux is going to help with the printing by loading into it every field if the space

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "\n\n--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

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

  fprintf(stdout, "---> Space Description :\n");
  printf("\t%s\n", space_get_description(space));

  fprintf(stdout, "---> Space Detailed Description :\n");
  printf("\t%s\n", space_get_det_description(space));

  fprintf(stdout, "---> Illuminate : ");
  if(space_get_illuminate(space) == TRUE) {
    printf("%s\n", "TRUE");
  } else {
    printf("%s\n", "FALSE");
  }

  return OK;
}
