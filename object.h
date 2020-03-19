/** 
 * @brief It defines the object struct
 * 
 * @file object.h
 * @author Evangelos Lazarakis
 * @version 1.0 
 * @date 10-02-2020
 */

#ifndef OBJECT_H
#define OBJECT_H


#include "types.h"

#define MAX_OBJECTS  20  //The maximum numbers of objects in a game

/**
 * @brief the Object structure
 * Stores the data of the Object
 */
typedef struct _Object Object;


/**
 * @brief Creates a object struct with the Id that is given as input
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param id the id that the new object is going to have
 * @return a pointer to the new object
 */
Object* object_create(Id id);

/**
 * @brief Deatroys a object struct
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param object the object that is going to be destroyed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS object_destroy(Object* object);

/**
 * @brief Get the Id of a object
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param object the object whose Id is going to be returned
 * @return the Id of the object
 */
Id object_get_id(Object* object);

/**
 * @brief Set the name of a object
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param object the object whose name is going to be changed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS object_set_name(Object* object, char* name);

/**
 * @brief Get the name of a object
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param object the object whose name is going to be returned
 * @return the name of the object
 */
const char* object_get_name(Object* object);

/**
 * @brief Print the data of a object
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param object the object whose data is going to be printed
 * @return a STATUS code, ERROR if any error occures or OK
 */
void object_print(Object* object);

#endif