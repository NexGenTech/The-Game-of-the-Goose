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
#include "link.h"


/**
 * @brief The Game structure
 * Stores the data of a game
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 */
typedef struct _Game* Game;

/**
 * @brief Creates a game
 *
 * Initializes all the fields of a Game struct
 *
 * @author Evangelos Lazarakis
 * @date 10-04-2015
 *
 * @return a pointer to the created Game struct
 */
Game game_create();

/**
 * @brief Creates a game from an open file
 *
 * Initializes all the fields of a Game struct using the game_create function
 * and sets the location of the player and the object on the game board
 *
 * @author Evangelos Lazarakis
 * @date 10-04-2015
 *
 * @param filename the name of the file from which the function is giong to get data
 * @return a pointer to the created Game struct
 */
Game game_create_from_file(char* filename);

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
STATUS game_update(Game game, T_Command cmd);

/**
 * @brief Destroys a game
 *
 * Gets a game as input and deallocates it's memory
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct that is going to be destroyed
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_destroy(Game game);

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
BOOL game_is_over(Game game);

/**
 * @brief Prints the data of a game
 *
 * Gets a game as input and prints it's fields
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct that is going to be printed
 */
void game_print_data(Game game);

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
Space* game_get_space(Game game, Id id);

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
Die* game_get_die(Game game);

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
Object* game_get_object(Game game, Id id);

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
 * @param position the position in the objects array
 * @return a pointer to the object that is in the position position
 */
Object* game_get_object_at(Game game, int position);

/**
 * @brief Gets an link from a game
 *
 * Gets an int as input and returns the link that is in that
 * position in the links array
 *
 * @author Evangelos Lazarakis
 * @date 25-03-2020
 *
 * @param game the game struct from which the link will be returned
 * @param position the position in the links array
 * @return a pointer to the link that is in the position position
 */
Link* game_get_link_at(Game game, int position);

/**
 * @brief Gets an space from a game
 *
 * Gets an int as input and returns the space that is in that
 * position in the spaces array
 *
 * @author Evangelos Lazarakis
 * @date 25-03-2020
 *
 * @param game the game struct from which the space will be returned
 * @param position the position in the spaces array
 * @return a pointer to the space that is in the position position
 */
Space* game_get_space_at(Game game, int position);

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
Player* game_get_player(Game game);

/**
 * @brief Gets the location Id of the player
 *
 * Gets a game as input and returns the location Id of the player
 *
 * @author Evangelos Lazarakis
 * @date 11-02-2020
 *
 * @param game the game struct whose player location Id will be returned
 * @return the location Id of the player
 */
Id game_get_player_location(Game game);

/**
 * @brief Gets the location Id of an object
 *
 * Gets a game and an object Id as input and returns the location Id of that object
 *
 * @author Evangelos Lazarakis
 * @date 29-02-2020
 *
 * @param game the game struct from which object location Id will be returned
 * @param object_id the object whose location Id will be returned
 * @return the location Id of the object
 */
Id game_get_object_location(Game game, Id object_id);

/**
 * @brief Gets the number of objects in the game
 *
 * Gets a game as input and returns the number of it's objects
 *
 * @author Evangelos Lazarakis
 * @date 29-02-2020
 *
 * @param game the game whose number of objects will be returned
 * @return the number of objects of the game
 */
int game_get_n_objects(Game game);

/**
 * @brief Gets the number of links in the game
 *
 * Gets a game as input and returns the number of it's links
 *
 * @author Evangelos Lazarakis
 * @date 29-02-2020
 *
 * @param game the game whose number of links of the game
 */
int game_get_n_links(Game game);

/**
 * @brief Gets the number of spaces in the game
 *
 * Gets a game as input and returns the number of it's spaces
 *
 * @author Evangelos Lazarakis
 * @date 29-02-2020
 *
 * @param game the game whose number of spaces of the game
 */
int game_get_n_spaces(Game game);

/**
 * @brief Gets the last command that was executed in the game
 *
 * Gets a game as input and returns the last command executed
 *
 * @author Profesores PPROG
 * @date 13-01-2015
 *
 * @param game the game struct whose last command is going to be returned
 * @return the last command that was executed in the game
 */
T_Command game_get_last_command(Game game);

/**
 * @brief Gets the last command's status that was executed in the game
 *
 * Gets a game as input and returns the status of the last command executed
 *
 * @author Evangelos Lazarakis
 * @date 29-02-2020
 *
 * @param game the game struct whose last command's status is going to be returned
 * @return the last command's status that was executed in the game
 */
STATUS game_get_last_command_status(Game game);

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
STATUS game_add_space(Game game, Space* space);

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
STATUS game_add_object(Game game, Object* object);

/**
 * @brief Adds a link to the game
 *
 * Inserts the link that it got as input at the first empty
 * slot in the links[] matrix of the game
 *
 * @author Evangelos Lazarakis
 * @date 30-03-2020
 *
 * @param game the game in which we want to add a link to
 * @param link the link we want to add
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_add_link(Game game, Link* link);

/**
 * @brief Adds a player to the game
 *
 * Gets a game and a player pointer as input and adds the player to the game
 *
 * @author Evangelos Lazarakis
 * @date 30-03-2020
 *
 * @param game the game in which we want to add a link to
 * @param player the player we want to add
 * @return a STATUS code, ERROR if any error occures or OK
 */
STATUS game_add_player(Game game, Player* player);

/**
 * @brief Sets the last_description of the game
 *
 * Gets a string as input and sets it as the game's last_description
 *
 * @date 05-04-2020
 * @author Evangelos Lazarakis
 *
 * @param game the game whose last_description will change
 * @param desc the new description of the game
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS game_set_last_description(Game game, char* desc);

/**
 * @brief Gets the last_description of the game
 *
 * Gets a game as input and returns a it's last_description
 *
 * @date 05-04-2020
 * @author Evangelos Lazarakis
 *
 * @param game the object whose last_description will be returned
 * @return a string with the object's description
 */
char* game_get_last_description(Game game);

/**
 * @brief Gets a link of the game
 *
 * Gets the game and the link's Id as input and returns a pointer to
 * that link
 *
 * @author Evangelos Lazarakis
 * @date 25-03-2020
 *
 * @param game the game struct from which the link will be returned
 * @return a pointer to the link of the game
 */
Link* game_get_link(Game game, Id id);

/**
 * @brief Clears the game
 *
 * Gets a game as input clears all of its fields
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param game  the game whose fields will be cleared
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS game_clear(Game game);

#endif
