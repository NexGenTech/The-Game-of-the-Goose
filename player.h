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

/**
 * @brief the Player structure
 * Stores the data of the player
 */
typedef struct _Player Player;

/**
 * @brief Creates a player struct with the Id that is given as input
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
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose location Id is going to be returned
 * @return the location Id of the player
 */
Id player_get_location(Player* player);

/**
 * @brief Set the object Id of a player
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose object Id is going to be changed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS player_set_object(Player* player,Id object);

/**
 * @brief Get the object Id of a player
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose object Id is going to be returned
 * @return the object Id of the player
 */
Id player_get_object(Player* player);

/**
 * @brief Print the data of a player
 *
 * @author Evangelos Lazarakis
 * @date 10-02-2020
 *
 * @param player the player whose data is going to be printed
 * @return a STATUS code, ERROR if any error occures or OK
 */
void player_print(Player* player);

#endif
