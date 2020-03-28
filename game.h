/**
 * @brief It defines the game interface
 * for each command
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "player.h"
#include "object.h"
#include "die.h"


/**
 * @brief The Game structure
 * Stores the data of a game
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 */
typedef struct _Game{
  Player* player;                        // A pointer to the player of the game
  Object* objects[MAX_OBJECTS + 1];      // A matrix with all the objects of the game
  Space* spaces[MAX_SPACES + 1];         // A matrix with all the spaces of the game
  Die* die;                              // A pointer to the die of the game
  T_Command last_cmd;                    // The last command executed in a game
  STATUS last_cmd_status;                // The status of the last command executed in a game
} Game;

/**
 * @brief Creates a game
 *
 * Initializes all the fields of a Game struct
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct that is going to be initialized
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_create(Game* game);

/**
 * @brief Creates a game from an open file
 *
 * Initializes all the fields of a Game struct using the game_create function
 * and sets the location of the player and the object on the game board
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct that is going to be initialized
 * @param filename the name of the file from which the function is giong to get data
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_create_from_file(Game* game, char* filename);

/**
 * @brief Updates a game
 *
 * Updates a game by executing the command that it gets as input
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct that is going to be updated
 * @param cmd the command that is going to be executed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_update(Game* game, T_Command cmd);

/**
 * @brief Destroys a game
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct that is going to be destroyed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_destroy(Game* game);

/**
 * @brief Returns FALSE
 *
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct that is not over
 * @return a BOOL code, FALSE if the game is not over
 */
BOOL game_is_over(Game* game);

/**
 * @brief Prints the data of a game
 *
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct that is going to be printed
 */
void game_print_data(Game* game);

/**
 * @brief Gets a space from a game
 *
 * Gets a space Id as input and returns the space that has that Id
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct from which the space will be returned
 * @param id the Id of the space that is going to be returned
 * @return a pointer to the space that its Id is equal with id
 */
Space* game_get_space(Game* game, Id id);

/**
 * @brief Gets the die of the game
 *
 * Gets the game as input and returns a pointer to
 * the die of the game
 *
 * @author Evangelos Lazarakis
 * @date 25-03-2020
 *
 * @param game the game struct from which the player will be returned
 * @return a pointer to the die of the game
 */
Die* game_get_die(Game* game);

/**
 * @brief Gets an object from a game
 *
 * Gets an object Id as input and returns the object that has that Id
 *
 * @author Evangelos Lazarakis
 * @date 07-02-2020
 *
 * @param game the game struct from which the object will be returned
 * @param id the Id of the object that is going to be returned
 * @return a pointer to the object that its Id is equal with id
 */
Object* game_get_object(Game* game, Id id);

/**
 * @brief Gets an object from a game
 *
 * Gets an int as input and returns the object that is in that
 * position in the objects array
 *
 * @author Evangelos Lazarakis
 * @date 25-03-2020
 *
 * @param game the game struct from which the object will be returned
 * @param pos the position in the objects array
 * @return a pointer to the object that is in the position pos
 */
Object* game_get_object_at(Game* game, int pos);

/**
 * @brief Gets the player of the game
 *
 * Gets the game as input and returns a pointer to
 * the player of the game
 *
 * @author Evangelos Lazarakis
 * @date 25-03-2020
 *
 * @param game the game struct from which the player will be returned
 * @return a pointer to the player of the game
 */
Player* game_get_player(Game* game);

/**
 * @brief Gets the location Id of the player
 *
 * Returns the location Id of the player
 *
 * @author Evangelos Lazarakis
 * @date 11-02-2020
 *
 * @param game the game struct whose player location Id will be returned
 * @return the location Id of the player
 */
Id game_get_player_location(Game* game);

/**
 * @brief Gets the location Id of an object
 *
 * Returns the location Id of an object
 *
 * @author Evangelos Lazarakis
 * @date 29-02-2020
 *
 * @param game the game struct from which object location Id will be returned
 * @param object_id the object whose location Id will be returned
 * @return the location Id of the object
 */
Id game_get_object_location(Game* game, Id object_id);

/**
 * @brief Gets the number of objects in the game
 *
 * @author Evangelos Lazarakis
 * @date 29-02-2020
 *
 * @param game the game whose number of objects will be returned
 * @return the number of objects of the game
 */
int game_get_n_objects(Game* game);

/**
 * @brief Gets the last command that was executed in the game
 *
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct whose last command is going to be returned
 * @return the last command that was executed in the game
 */
T_Command game_get_last_command(Game* game);

/**
 * @brief Gets the last command's status that was executed in the game
 *
 *
 * @author Evangelos Lazarakis
 * @date 29-02-2020
 *
 * @param game the game struct whose last command's status is going to be returned
 * @return the last command's status that was executed in the game
 */
STATUS game_get_last_command_status(Game* game);

/**
 * @brief Adds a space to the game
 *
 * Inserts the space that it got as input at the first empty
 * slot in the spaces[] matrix of the game
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game in which we want to add a space to
 * @param space the space we want to add
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_add_space(Game* game, Space* space);

/**
 * @brief Adds an object to the game
 *
 * Inserts the object that it got as input at the first empty
 * slot in the objects[] matrix of the game
 *
 * @author Evangelos Lazarakis
 * @date 03-03-2020
 *
 * @param game the game in which we want to add an object to
 * @param object the object we want to add
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_add_object(Game* game, Object* object);

#endif
