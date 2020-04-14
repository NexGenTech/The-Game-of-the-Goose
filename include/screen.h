/** 
 * @brief It defines a screen
 * 
 * @file screen.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 11-01-2017
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80      //The maxim size of a string that is printable in the game screen

typedef struct _Area Area;

/**
 * @brief Initializes the screen
 *
 * @author Profesores PPROG
 * @date 11-01-2017
 */
void  screen_init();

/**
 * @brief Destroys the screen
 *
 * @author Profesores PPROG
 * @date 11-01-2017
 */
void  screen_destroy();

/**
 * @brief Paints the screen in the terminal
 *
 * @author Profesores PPROG
 * @date 11-01-2017
 */
void  screen_paint();

/**
 * @brief Initializes the screen
 *
 * @author Profesores PPROG
 * @date 11-01-2017
 */
void  screen_gets(char *str);

/**
 * @brief Initializes a new created area
 *
 * @author Profesores PPROG
 * @date 11-01-2017
 *
 * @param x
 * @param y
 * @param width
 * @param height
 * @return the created and initialized area
 */
Area* screen_area_init(int x, int y, int width, int height);

/**
 * @brief Destroys an area
 *
 * @author Profesores PPROG
 * @date 11-01-2017
 * 
 * @param area the area that is going to be destroyed
 */
void  screen_area_destroy(Area* area);

/**
 * @brief Clears an area
 *
 * @author Profesores PPROG
 * @date 11-01-2017
 * 
 * @param area the area that is going to be cleared
 */
void  screen_area_clear(Area* area);

/**
 * @brief Resets the cursor
 *
 * @author Profesores PPROG
 * @date 11-01-2017
 * 
 * @param area the area in which the cursor is going to be reset
 */
void  screen_area_reset_cursor(Area* area);


void  screen_area_puts(Area* area, char *str);

#endif
