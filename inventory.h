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
 STATUS inventory_add_object(Inventory* inventory, Id object);

 /**
  * @brief Deletes an object from the inventory
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
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param inventory the inventory from which we want an Id
  * @param position the position in the ids array whose object id will be returned
  * @return the Id of the specific position in the ids array
  */
  Id inventory_get_Object_at(Inventory* inventory, int position);

 /**
  * @brief Get the max number of objects that can be added to the Inventory
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param inventory the inventory whose max number of objects will be returned
  * @return the max max number of objects of the Inventory
  */
  int inventory_get_max_objects(Inventory* inventory);

  /**
   * @brief Set the max number of objects that can be added to the Inventory
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
   * @author Evangelos Lazarakis
   * @date 26-02-2020
   *
   * @param inventory the inventory in which we are searching for
   * @param object the object for which we are searching in the inventory
   * @return NO_ID if we did not find the object in the inventory, otherwise return object
   */
  Id inventory_search_object(Inventory inventory, Id object);

 /**
  * @brief Print the data of a inventory
  *
  * @author Evangelos Lazarakis
  * @date 27-03-2020
  *
  * @param inventory the inventory whose data is going to be printed
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS inventory_print(Inventory* inventory);

#endif
