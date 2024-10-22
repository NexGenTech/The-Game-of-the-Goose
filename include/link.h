/**
 * @brief It defines the link struct
 *
 *@file link.h
 *@author Evangelos Lazarakis
 *@date 28/03/2020
 *
 */


#ifndef LINK_H
#define LINK_H

#include "types.h"

#define MAX_LINKS 100              // The maximum number of links in a game

typedef enum {
  OP, CL
} LINK_STATUS;

/**
 *@brief The Link structure
 *
 * Stores linking between Spaces
 */
typedef struct _Link Link;

/**
 * @brief Creates a link struct
 *
 * Gets an Id as input, allocates memory for a link with this Id and returns a pointer to it
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param id the id of the new link
 * @return a pointer to the new link
 */
Link* link_create(Id id);

/**
 * @brief Destroys a link struct
 *
 * Gets a link as input and deallocates it's memory
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link that is going to be destroyed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS link_destroy(Link* link);

/**
 * @brief Set the name of a link
 *
 * Gets an inventory and a string as input and sets the string as the name of the link
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose name is going to be changed
 * @param name is the new name of the link
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS link_set_name(Link* link, char* name);

/**
 * @brief Get the name of a link
 *
 * Gets an inventory as input and returns it's name
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose name is going to be returned
 * @return the name of the link
 */
const char* link_get_name(Link* link);

/**
 * @brief Get the Id of a link
 *
 * Gets an inventory as input and returns it's Id
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose Id is going to be returned
 * @return the Id of the link
 */
Id link_get_id(Link* link);

/**
 * @brief Get the status of a link
 *
 * Gets an inventory as input and returns it's status
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose status will be returned
 * @return the status of the link
 */
LINK_STATUS link_get_status(Link* link);

/**
 * @brief Set the status of a link
 *
 * Gets an inventory and a status as input and updates the status of the link
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose status will be returned
 * @param status the new status of the link
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS link_set_status(Link* link, LINK_STATUS status);

/**
 * @brief Get the id of the first space of the link
 *
 * Gets an inventory as input and returns the Id of the first space
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose first space's id will returned
 * @return the id of the first space of the linked*/
Id link_get_space_one_id(Link* link);

/**
 * @brief Get the id of the second space of the link
 *
 * Gets an inventory as input and returns the Id of the second space
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose second space's id will returned
 * @return the id of the second space of the linked*/
Id link_get_space_two_id(Link* link);

/**
 * @brief Set the id of the first space of the link
 *
 * Gets an inventory and an Id as input and sets it as the Id of the link's first space
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose first space's id will changed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS link_set_space_one_id(Link* link, Id id);

/**
 * @brief Set the id of the second space of the link
 *
 * Gets an inventory and an Id as input and sets it as the Id of the link's second space
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose second space's id will changed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS link_set_space_two_id(Link* link, Id id);

/**
 * @brief Gets one of the space Ids in a link and
 * returns the other one
 *
 * Gets an inventory and an Id as input and returns the Id of the other space
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link from which we want to get the other space Id
 * @param space the space id of one of the two spaces in the link
 * @return the id of the other space
 */
Id link_get_other(Link* link, Id space);

/**
 * @brief Print the data of a link
 *
 * Gets an inventory as input and prints it's fields
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the set whose data is going to be printed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS link_print(Link* link);

#endif
