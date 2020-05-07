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
 *
 * Stores the data of the Object
 */
typedef struct _Object Object;


/**
 * @brief Creates a object struct with the Id that is given as input
 *
 * Gets an Id as input, allocates memory for an object and returns a pointer to it
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
 * Gets an object as input and deallocates it's memory
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
 * Gets an object as input and returns it's Id
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
 * Gets an object and an Id as input and sets it as the object's Id
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
 * Gets an object as input and returns it's name
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param object the object whose name is going to be returned
 * @return the name of the object
 */
const char* object_get_name(Object* object);

/**
 * @brief Sets the description of the object
 *
 * Gets a string as input and sets it as the object's description
 *
 * @date 05-04-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose description will change
 * @param desc the new description of the object
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS object_set_description(Object* object, char* desc);

/**
 * @brief Gets the description of the object
 *
 * Gets an object as input and returns it's description
 *
 * @date 05-04-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose description will be returned
 * @return a string with the object's description
 */
char* object_get_description(Object* object);

/**
 * @brief Sets if the object is movalbe
 *
 * Gets a BOOL as input and sets it as the object's movable state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose movable state will change
 * @param movable the movable state of the object
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS object_set_movable(Object* object, BOOL movable);

/**
 * @brief Gets the movable state of the object
 *
 * Gets an object as input and returns it's movable state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose movable state will be returned
 * @return a BOOL with the object's movable state
 */
BOOL object_get_movable(Object* object);

/**
 * @brief Sets if the object can open a link
 *
 * Gets a BOOL as input and sets it as the object's open state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose open state will change
 * @param move the open state of the object
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS object_set_open(Object* object, Id open);

/**
 * @brief Gets the open state of the object
 *
 * Gets an object as input and returns it's open state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose open state will be returned
 * @return the Id of the link that the object can open
 */
Id object_get_open(Object* object);

/**
 * @brief Sets if the object is hidden
 *
 * Gets a BOOL as input and sets it as the object's hidden state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose hidden state will change
 * @param move the hidden state of the object
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS object_set_hidden(Object* object, BOOL hidden);

/**
 * @brief Gets the movable hidden of the object
 *
 * Gets an object as input and returns it's hidden state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose hidden state will be returned
 * @return a BOOL with the object's hidden state
 */
BOOL object_get_hidden(Object* object);

/**
 * @brief Sets if the object is illuminatable
 *
 * Gets a BOOL as input and sets it as the object's illuminate state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose illuminate state will change
 * @param move the illuminate state of the object
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS object_set_illuminate(Object* object, BOOL illuminate);

/**
 * @brief Gets the illuminate state of the object
 *
 * Gets an object as input and returns it's illuminate state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose illuminate state will be returned
 * @return a BOOL with the object's illuminate state
 */
BOOL object_get_illuminate(Object* object);

/**
 * @brief Sets if the object is turned on
 *
 * Gets a BOOL as input and sets it as the object's turnedon state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose turnedon state will change
 * @param move the turnedon state of the object
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS object_set_turnedon(Object* object, BOOL turnedon);

/**
 * @brief Gets the turnedon state of the object
 *
 * Gets an object as input and returns it's turnedon state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose turnedon state will be returned
 * @return a BOOL with the object's turnedon state
 */
BOOL object_get_turnedon(Object* object);

/**
 * @brief Sets the object's dependency
 *
 * Gets an Object Id as input and sets it as the object's dependency
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose dependency will change
 * @param move the object Id of the dependency
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS object_set_dependency(Object* object, Id dependency);

/**
 * @brief Gets the dependency of the object
 *
 * Gets an object as input and returns it's dependency
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose dependency will be returned
 * @return an Id which is the object's dependency
 */
Id object_get_dependency(Object* object);

/**
 * @brief Sets the object's incompatibility
 *
 * Gets an Object Id as input and sets it as the object's incompatibility
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose incompatibility will change
 * @param move the object Id of the incompatibility
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS object_set_incompatible(Object* object, Id incompatible);

/**
 * @brief Gets the incompatibility of the object
 *
 * Gets an object as input and returns it's incompatibility
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param object the object whose incompatibility will be returned
 * @return an Id which is the object's incompatibility
 */
Id object_get_incompatible(Object* object);


/**
 * @brief Print the data of a object
 *
 * Gets an object as input and prints it's fields
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param object the object whose data is going to be printed
 * @return a STATUS code, ERROR if any error occures or OK
 */
void object_print(Object* object);

#endif
