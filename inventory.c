/**
 * @brief It defines the inventory struct
 *
 *@file inventory.h
 *@author Evangelos Lazarakis
 *@date 27/03/2020
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

typedef struct _Inventory {
  Set* objects;
  int max_objects;
}Inventory;

Inventory* inventory_create() {
   Inventory* newInventory = NULL;

   newInventory = (Inventory*) malloc(sizeof(Inventory));

   if (newInventory == NULL) {
      return NULL;
   }

   newInventory->objects = set_create();

   newInventory->max_objects = 0;

   return newInventory;
}

STATUS inventory_destroy(Inventory* inventory) {
  if (!inventory) {
    return ERROR;
  }

  free(inventory->objects);
  free(inventory);
  inventory = NULL;

  return OK;
}

STATUS inventory_add_object(Inventory* inventory, Id object) {
  if (!inventory) {
    return ERROR;
  }

  if ((set_get_n_ids(inventory->objects)) < inventory->max_objects){
    return set_add(inventory->objects, object);
  } else {
    return ERROR;
  }
}

STATUS inventory_del_object(Inventory* inventory, Id object) {
  if (!inventory) {
    return ERROR;
  }

  return set_del(inventory->objects, object);
}

Id inventory_get_object_at(Inventory* inventory, int position) {
    return set_get_id_at(inventory->objects, position);
}

int inventory_get_max_objects(Inventory* inventory) {
  return inventory->max_objects;
}

STATUS inventory_set_max_objects(Inventory* inventory, int max) {
  if (!inventory) {
    return ERROR;
  }

  if (!(inventory->max_objects = max)) {
    return ERROR;
  }

  return OK;
}

Id inventory_search_object(Inventory* inventory, Id object) {
  return set_search_id(inventory->objects, object);
}

STATUS inventory_has_space(Inventory* inventory) {
  if ((set_get_n_ids(inventory->objects)) == inventory->max_objects) {
    return ERROR;
  } else {
    return OK;
  }
}

STATUS inventory_print(Inventory* inventory) {
  if (!inventory) {
    return ERROR;
  }
  int i = 0;
  printf("The Inventory can carry at best %d and has the following %d objects stored:\n", inventory_get_max_objects(inventory), set_get_n_ids(inventory->objects));
  for(Id id = set_get_id_at(inventory->objects, i); id != NO_ID; id = set_get_id_at(inventory->objects, ++i)) {
    printf("  %ld\n",id );
  }
}
