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

  Inventory* invenotry_create() {
    Inventory* newInventory = NULL;

    newInventory = (Inventory*) malloc(sizeof(Inventory));

    if (newInventory == NULL) {
      return NULL;
    }

    newInventory->objects = set_create();

    newInventory->max_objects = MAX_ITEMS;

    return newInventory;
  }

  
