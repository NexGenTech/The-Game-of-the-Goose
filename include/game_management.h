/**
 * @brief It defines the game management
 *
 * @file game_management.h
 * @author Adam Mahjoub
 * @version 1.0
 * @date 13-02-2020
 */

#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "game.h"

/**
 * @brief Loads spaces from a file
 *
 * Gets a game and a filename as input and adds the spaces it read from the file
 *
 * @author Adam Mahjoub
 * @date 13-02-2020
 *
 * @param game the game that we want to load the spaces to
 * @param filename the file that we are going to load the spaces from
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_management_load_spaces(Game game, char* filename);

/**
 * @brief Loads objects from a file
 *
 * Gets a game and a filename as input and adds the objects it read from the file
 *
 * @author Adam Mahjoub
 * @date 13-02-2020
 *
 * @param game the game that we want to load the objects to
 * @param filename the file that we are going to load the objects from
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_management_load_objects(Game game, char* filename);

/**
 * @brief Loads players from a file
 *
 * Gets a game and a filename as input and adds the players it read from the file
 *
 * @author Evanglelos Lazarakis
 * @date 28-03-2020
 *
 * @param game the game that we want to load the players to
 * @param filename the file that we are going to load the players from
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_management_load_players(Game game, char* filename);

/**
 * @brief Loads links from a file
 *
 * Gets a game and a filename as input and adds the links it read from the file
 *
 * @author Evanglelos Lazarakis
 * @date 28-03-2020
 *
 * @param game the game that we want to load the links to
 * @param filename the file that we are going to load the links from
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_management_load_links(Game game, char* filename);

/**
 * @brief Saves the game state to a file
 *
 * Gets a game and a filename as input and saves the game state to the file
 *
 * @author Evanglelos Lazarakis
 * @date 06-05-2020
 *
 * @param game the game that we want to save to the file
 * @param filename the file that we are going to save the game to
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_management_save(Game game, char* filename);

/**
 * @brief Loads a game state from a file
 *
 * Gest a game and a filename as input and loads a game state
 * from the file to the game
 *
 * @author Evanglelos Lazarakis
 * @date 06-05-2020
 *
 * @param game the game that we want to load the game state to
 * @param filename the file that we are going to load the game state from
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_management_load(Game game, char* filename);

#endif
