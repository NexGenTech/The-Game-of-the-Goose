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
  OPEN, CLOSED
} LINK_STATUS;

/**
 *@brief The Link structure
 * Stores linking between Spaces
 */
typedef struct _Link Link;

/**
 * @brief Creates a link struct
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param id the id of the new link
 * @return a pointer to the new link
 */
Link* link_create(Id id);

/**
 * @brief Deatroys a link struct
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
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose Id is going to be returned
 * @return the Id of the link
 */
Id link_get_id(Link* link);

/**
 * @ Get the status of a link
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose status will be returned
 * @return the status of the link
 */
LINK_STATUS link_get_status(Link* link);

/**
 * @ Set the status of a link
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
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose first space's id will returned
 * @return the id of the first space of the linked*/
Id link_get_space_one_id(Link* link);

/**
 * @brief Get the id of the second space of the link
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
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the link whose second space's id will changed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS link_set_space_two_id(Link* link, Id id);

/**
 * @brief Print the data of a link
 *
 * @author Evangelos Lazarakis
 * @date 28-03-2020
 *
 * @param link the set whose data is going to be printed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS link_print(Link* link);

#endif
