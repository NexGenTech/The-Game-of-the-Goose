/**
 * @brief It implements the object struct and all
 * of its functions
 *
 * @file object.c
 * @author Evangelos Lazarakis
 * @version 1.0
 * @date 10-02-2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"


typedef struct _Object{
  Id id;                              // The Id of the object
  char name[WORD_SIZE + 1];           // The name of the object
  char description[WORD_SIZE + 1];    // A description of the object
  BOOL movable;                       // Specifies if the object is movable
  BOOL hidden;                        // Specifies if the object is hidden
  Id open;                            // The Id of the link that the object can open
  BOOL illuminate;                    // Specifies if the object can illuminate
  BOOL turnedon;                      // Specifies if an object illuminateable object is turned on
}Object;



Object* object_create(Id id){

  Object *newObject = NULL;

    newObject = (Object *) malloc(sizeof (Object));

    if (newObject == NULL) {
      return NULL;
    }

    newObject->id = id;
    newObject->name[0] = '\0';
    newObject->description[0] = '\0';
    newObject->movable = FALSE;
    newObject->hidden = FALSE;
    newObject->open = NO_ID;
    newObject->illuminate = FALSE;
    newObject->turnedon = FALSE;

  return newObject;
}

STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}

const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}

STATUS object_set_description(Object* object, char* desc) {

  if(desc == NULL) {
    return ERROR;
  }

  strcpy(object->description, desc);

  return OK;
}

char* object_get_description(Object* object) {
  return object->description;
}

STATUS object_set_movable(Object* object, BOOL move) {
  if (!object || !move) {
    return ERROR;
  }

  object->move = move;

  return OK;
}
BOOL object_get_movable(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->movable;
}
STATUS object_set_open(Object* object, Id open) {
  if (!object || !open) {
    return ERROR;
  }

  object->open = open;

  return OK;
}
Id object_get_open(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->open;
}
STATUS object_set_hidden(Object* object, BOOL hidden) {
  if (!object || !hidden) {
    return ERROR;
  }

  object->hidden = hidden;

  return OK;
}
BOOL object_get_hidden(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->hidden;
}
STATUS object_set_illuminate(Object* object, BOOL illuminate) {
  if (!object || !illuminate) {
    return ERROR;
  }

  object->illuminate = illuminate;

  return OK;
}
BOOL object_get_illuminate(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->illuminate;
}
STATUS object_set_turnedon(Object* object, BOOL turnedon) {
  if (!object || !turnedon) {
    return ERROR;
  }

  if(object->illuminate == TRUE){
    object->turnedon = turnedon;
    return OK;
  } else {
    return ERROR;
  }
}

BOOL object_get_turnedon(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->turnedon;
}

void object_print(Object* object){

  printf("The object with id %ld:\n \tname: %s\n \tdescription: %s\n \topen id: %ld\n",object->id,object->name, object->description, object->open);

  if(object->movable == TRUE) {
    printf("\t movable: %s","TRUE");
  } else {
    printf("\t movable: %s","FALSE");
  }

  if(object->hidden == TRUE) {
    printf("\t hidden: %s","TRUE");
  } else {
    printf("\t hidden: %s","FALSE");
  }

  if(object->illuminate == TRUE) {
    printf("\t illuminate: %s","TRUE");
  } else {
    printf("\t illuminate: %s","FALSE");
  }
  if(object->turnedon == TRUE) {
    printf("\t turned on: %s","TRUE");
  } else {
    printf("\t turned on: %s","FALSE");
  }
}
