/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 18-01-2017
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"
#include "screen.h"

typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief Creates a Graphic_engine struct
 *
 * Creates a Graphic_engine struct and returns it
 *
 * @author Profesores PPROG
 * @date 18-01-2017
 *
 * @return a pointer to the created Graphic_engine
 */
Graphic_engine* graphic_engine_create();

/**
 * @brief Destroys a Graphic_engine struct
 *
 * Gets a Graphic_engine as input and deallocates it's memory
 *
 * @author Profesores PPROG
 * @date 18-01-2017
 *
 * @param ge the Graphic_engine that is going to be destroyed
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief Prints a game onto the terminal
 *
 * Gets a Graphic_engine and a game as input and prints the game into the screen
 *
 * @author Profesores PPROG
 * @date 18-01-2017
 *
 * @param ge a Graphic_engine
 * @param game the game that is going to be printed
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game game);

#endif
