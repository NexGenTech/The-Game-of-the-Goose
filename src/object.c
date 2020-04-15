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

void object_print(Object* object){

  printf("The object with id %ld, name %s  and  description %s\n",object->id,object->name, object->description);
}
