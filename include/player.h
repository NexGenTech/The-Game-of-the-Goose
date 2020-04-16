/**
 * @brief It defines the player struct
 *
 * @file player.h
 * @author Evangelos Lazarakis
 * @version 1.0
 * @date 10-02-2020
 */

#ifndef PLAYER_H
#define PLAYER_H


#include "types.h"
#include "inventory.h"

/**
 * @brief the Player structure
 *
 * Stores the data of the player
 */
typedef struct _Player Player;

/**
 * @brief Creates a player struct with the Id that is given as input
 *
 * Gets an Id as input, allocates memory for a player and returns a pointer to it
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param id the id that the new player is going to have
 * @return a pointer to the new player
 */
Player* player_create(Id id);

/**
 * @brief Deatroys a player struct
 *
 * Gets a player as input and deallocates it's memory
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player that is going to be destroyed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS player_destroy(Player* player);

/**
 * @brief Get the Id of a player
 *
 * Gets a player as input and returns it's id
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose Id is going to be returned
 * @return the Id of the player
 */
Id player_get_id(Player* player);

/**
 * @brief Set the name of a player
 *
 * Gets a player and a string as input and sets it as the player's name
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose name is going to be changed
 * @param name is the new name of the player
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS player_set_name(Player* player, char* name);

/**
 * @brief Get the name of a player
 *
 * Gets a player as input and returns it's name
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose name is going to be returned
 * @return the name of the player
 */
const char* player_get_name(Player* player);

/**
 * @brief Set the location Id of a player
 *
 * Gets a player and an Id as input and sets it as it's location
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose location Id is going to be changed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS player_set_location(Player* player, Id location);

/**
 * @brief Get the location Id of a player
 *
 * Gets a player as input and returns it's location Id
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose location Id is going to be returned
 * @return the location Id of the player
 */
Id player_get_location(Player* player);

/**
 * @brief Add an object to the player"s backpack
 *
 * Gets a player and an Id as input and adds it to the player's backpack
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player that an object will be added to his backpack
 * @paeam object the object that will be added to the player's backpack
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS player_add_object(Player* player,Id object);

/**
 * @brief Delete an object to the player"s backpack
 *
 * Gets a player and an Id as input and removes it from the player's backpack
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player that an object will be deleteed to his backpack
 * @paeam object the object that will be deleteed to the player's backpack
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS player_del_object(Player* player,Id object);

/**
 * @brief Search if an object exists in the backpack of a player
 *
 * Gets a player and an Id as input and returns it if it is in the backpack
 *
 * @author Evangelos Lazarakis
 * @date 26-02-2020
 *
 * @param player the player in whose backpack we are searching for
 * @param object the object for which we are searching in the backpack
 * @return NO_ID if we did not find the object in the backpack, otherwise return object
 */
Id player_search_object(Player* player, Id object);

/**
 * @brief Change the size of the player's backpack
 *
 * Gets a player and an integer as input and sets it as it's backpack size
 *
 * @author Evangelos Lazarakis
 * @date 30-03-2020
 *
 * @param player the player whose backpack's size will be changed
 * @param size the new size of the player's backpack
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS player_set_backpack_size(Player* player, int size);

/**
 * @brief Checks if a player's backpack is full or not
 *
 * Gets a player as input and returns if it's backpack has free space
 *
 * @author Evangelos Lazarakis
 * @date 30-03-2020
 *
 * @param player the player whose backpack will be checked
 * @return a STATUS code, ERROR if the backpack is full or OK otherwise
 */
STATUS player_backpack_has_space(Player* player);

/**
 * @brief Print the data of a player
 *
 * Gets a player as input and prints its fields
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose data is going to be printed
 * @return a STATUS code, ERROR if any error occures or OK
 */
void player_print(Player* player);

#endif
