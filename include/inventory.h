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

 #include "set.h"

 /**
  *@brief The Inventory structure
  *
  * Stores the Id of many Object structs
  */
 typedef struct _Inventory Inventory;

 /**
  * @brief Creates a inventory struct
  *
  * Allocates memory for an Inventory and returns a pointer to that Invenotry
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @return a pointer to the new inventory
  */
 Inventory* inventory_create();

 /**
  * @brief Destroys a inventory struct
  *
  * Gets an inventory as input and deallocates it's memory
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
  * Gets an inventory and an Id as input and adds it to the inventory
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param object the object id that is going to be added to the inventory
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS inventory_add_object(Inventory* inventory, Id object);

 /**
  * @brief Deletes an object from the inventory
  *
  * Gets an inventory and an Id as input and removes it from the inventory
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param object the object id that is going to be deleted from the inventory
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS inventory_del_object(Inventory* inventory, Id object);

 /**
  * @brief Gets the object Id in a certain position in the ids array
  *
  * Gets an inventory and an index as input nad returns the Id that is stored in that index in the inventory
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param inventory the inventory from which we want an Id
  * @param position the position in the ids array whose object id will be returned
  * @return the Id of the specific position in the ids array
  */
  Id inventory_get_object_at(Inventory* inventory, int position);

 /**
  * @brief Get the max number of objects that can be added to the Inventory
  *
  * Gets an inventory as input and returns the maximum number of Ids that it can contain
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param inventory the inventory whose max number of Ids will be returned
  * @return the max max number of objects of the Inventory
  */
  int inventory_get_max_objects(Inventory* inventory);

  /**
   * @brief Set the max number of objects that can be added to the Inventory
   *
   * Gets an inventory and an integer as input and sets the int as the maximum number of Ids that it can contain
   *
   * @author Evangelos Lazarakis
   * @date 27-03-2020
   *
   * @param inventory the inventory whose max number of objects will be changed
   * @param the new max number of objects of the inventory
   * @return the max max number of objects of the Inventory
   */
  STATUS inventory_set_max_objects(Inventory* inventory, int max);

  /**
   * @brief Search if an object exists in the inventory
   *
   * Gets an inventory and an Id as input and returns if the inventory contains it or not
   *
   * @author Evangelos Lazarakis
   * @date 26-02-2020
   *
   * @param inventory the inventory in which we are searching for
   * @param object the object for which we are searching in the inventory
   * @return NO_ID if we did not find the object in the inventory, otherwise return object
   */
  Id inventory_search_object(Inventory* inventory, Id object);

  /**
   * @brief Checks if an inventory is full or not
   *
   * Gets an inventory as input and returns if it has free space or not
   *
   * @author Evangelos Lazarakis
   * @date 30-03-2020
   *
   * @param inventory the inventory which will be checked
   * @return a STATUS code, ERROR if the inventory is full or OK otherwise
   */
  STATUS inventory_has_space(Inventory* inventory);

 /**
  * @brief Print the data of a inventory
  *
  * Gets an inventory as input and prints its fields
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param inventory the inventory whose data is going to be printed
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS inventory_print(Inventory* inventory);

#endif
