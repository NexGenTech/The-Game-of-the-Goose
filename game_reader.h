/**
 * @brief It defines the game reader
 *
 * @file game_reader.h
 * @author Adam Mahjoub
 * @version 1.0
 * @date 13-02-2020
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"

/**
 * @brief Loads spaces from a file
 *
 * @author Adam Mahjoub
 * @date 13-02-2020
 *
 * @param game the game that we want to load the spaces to
 * @param filename the file that we are going to load the spaces from
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_reader_load_spaces(Game game, char* filename);

/**
 * @brief Loads objects from a file
 *
 * @author Adam Mahjoub
 * @date 13-02-2020
 *
 * @param game the game that we want to load the objects to
 * @param filename the file that we are going to load the objects from
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_reader_load_objects(Game game, char* filename);

/**
 * @brief Loads players from a file
 *
 * @author Adam Mahjoub
 * @date 28-03-2020
 *
 * @param game the game that we want to load the players to
 * @param filename the file that we are going to load the players from
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_reader_load_players(Game game, char* filename);

#endif
