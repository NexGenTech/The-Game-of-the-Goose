/**
 * @brief It defines the set struct
 *
 *@file set.h
 *@author Evangelos Lazarakis
 *@date 18/02/2020
 *
 */

 #ifndef SET_H
 #define SET_H

 #include "object.h"

 #define MAX_CAPACITY 100                    // The maximum number of Id's that can be stored in a set

/**
 *@brief The Set structure
 *
 * Stores the Id of many Object structs
 */
typedef struct _Set Set;

/**
 * @brief Creates a set struct
 *
 * Allocates memory for a set and returns a pointer to it
 *
 * @author Evangelos Lazarakis
 * @date 26-02-2020
 *
 * @return a pointer to the new set
 */
Set* set_create();

/**
 * @brief Destroys a set struct
 *
 * Gets a set as input and deallocates it's memory
 *
 * @author Evangelos Lazarakis
 * @date 26-02-2020
 *
 * @param set the set that is going to be destroyed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS set_destroy(Set* set);

/**
 * @brief Adds an Id to the set
 *
 * Gets a set and an Id as input and adds it in the set
 *
 * @author Evangelos Lazarakis
 * @date 26-02-2020
 *
 * @param id the id that is going to be added to the set
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS set_add(Set* set, Id id);

/**
 * @brief Deletes an Id from the set
 *
 * Gets a set and an Id as input and removes it from the set
 *
 * @author Evangelos Lazarakis
 * @date 26-02-2020
 *
 * @param id the id that is going to be deleted from the set
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS set_del(Set* set, Id id);

/**
 * @brief Search if an Id exists in the set
 *
 * Gets a set and an Id as input and returns if it is in the set
 *
 * @author Evangelos Lazarakis
 * @date 26-02-2020
 *
 * @param set the set in which we are searching for
 * @param id the id for which we are searching in the set
 * @return NO_ID if we did not find the id in the set, otherwise return id
 */
Id set_search_id(Set* set, Id id);

/**
* @brief Gets the number of Id's of the set
*
* Gets a set as input and returns the number of it's total Ids
*
* @author Evangelos Lazarakis
* @date 26-02-2020
*
* @param set the set from which we want its number of Id's
* @return the set's number of Id's
*/
int set_get_n_ids(Set* set);

/**
 * @brief Gets the Id in a certain position in the ids array
 *
 * Gets a set and an index as input and returns the Id that is in that index in the set
 *
 * @author Evangelos Lazarakis
 * @date 26-02-2020
 *
 * @param set the set from which we want an Id
 * @param position the position in the ids array whose id will be returned
 * @return the Id of the specific position in the ids array
 */
 Id set_get_id_at(Set* set, int position);

/**
 * @brief Print the data of a set
 *
 * Gets a set as input and prints it's fields
 *
 * @author Evangelos Lazarakis
 * @date 26-02-2020
 *
 * @param set the set whose data is going to be printed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS set_print(Set* set);

#endif
