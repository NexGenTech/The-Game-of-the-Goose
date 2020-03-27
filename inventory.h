/**
 * @brief It defines the inventory struct
 *
 *@file inventory.h
 *@author Evangelos Lazarakis
 *@date 27/03/2020
 *
 */

 #ifndef INVENTORY_H
 #define INVENTORY_H

 #include "inventory.h"

 #define MAX_ITEMS 20                    // The maximum number of objects that can be stored in an Inventory

 /**
  *@brief The Inventory structure
  * Stores the Id of many Object structs
  */
 typedef struct _Inventory Inventory;

 /**
  * @brief Creates a inventory struct
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @return a pointer to the new inventory
  */
 Inventory* inventory_create();

 /**
  * @brief Deatroys a inventory struct
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param inventory the inventory that is going to be destroyed
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS inventory_destroy(Inventory* inventory);

 /**
  * @brief Adds an object to the inventory
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param object the object id that is going to be added to the inventory
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS inventory_add(Inventory* inventory, Id object);

 /**
  * @brief Deletes an object from the inventory
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param object the object id that is going to be deleted from the inventory
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS inventory_del(Inventory* inventory, Id object);
