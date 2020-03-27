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

   newInventory->max_objects = MAX_ITEMS;

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

  return set_add(inventory->objects, object);
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

STATUS inventory_print(Inventory* inventory) {
  if (!inventory) {
    return ERROR;
  }
  int i = 0;
  printf("The Inventory has the following objects:\n");
  for(Id id = set_get_id_at(inventory->objects, i); id != NO_ID; id = set_get_id_at(inventory->objects, ++i)) {
    printf("  %ld\n",id );
  }
}
