/**
 * @brief It defines a space
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

#define MAX_SPACES 100               // The maximum number of spaces that a game can have
#define FIRST_SPACE 1                // The number of the first space


/**
* @brief The Space structure
*
* It stores all the information of a space in a board game
*/
typedef struct _Space Space;


/**
 * @brief Creates a space
 *
 * space_create creates a space with the Id that it is given
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param id  is the Id of the space that is going to be created
 * @return a pointer to the created space
 */
Space* space_create(Id id);

/**
 * @brief Destroys a space
 *
 * space_destroy destroys a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space that is going to be destroyed
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_destroy(Space* space);

/**
 * @brief Gets the Id of a space
 *
 * space_get_id gets the Id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space whose Id we want to get
 * @return the Id of the space
 */
Id space_get_id(Space* space);

/**
 * @brief Sets the name of a space
 *
 * space_set_name changes the name of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space that we want to change its name
 * @param name is the new name of the space
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_set_name(Space* space, char* name);

/**
 * @brief Gets the name of a space
 *
 * space_get_name gets the name of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space whose name we want to get
 * @return the name of the space
 */
const char* space_get_name(Space* space);

/**
 * @brief Sets the north id of a space
 *
 * space_set_north changes the north id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space that we want to change its north id
 * @param id is the new north id of the space
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_set_north(Space* space, Id id);

/**
 * @brief Gets the north id of a space
 *
 * space_get_north gets the north id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space whose north id we want to get
 * @return the north id of the space
 */
Id space_get_north(Space* space);

/**
 * @brief Sets the south id of a space
 *
 * space_set_south changes the south id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space that we want to change its south id
 * @param id is the new south id of the space
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_set_south(Space* space, Id id);

/**
 * @brief Gets the south id of a space
 *
 * space_get_south gets the south id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space whose south id we want to get
 * @return the south id of the space
 */
Id space_get_south(Space* space);

/**
 * @brief Sets the east id of a space
 *
 * space_set_east changes the east id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space that we want to change its east id
 * @param id is the new east id of the space
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_set_east(Space* space, Id id);

/**
 * @brief Gets the east id of a space
 *
 * space_get_east gets the east id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space whose east id we want to get
 * @return the east id of the space
 */
Id space_get_east(Space* space);

/**
 * @brief Sets the west id of a space
 *
 * space_set_west changes the west id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space that we want to change its west id
 * @param id is the new west id of the space
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_set_west(Space* space, Id id);

/**
 * @brief Gets the west id of a space
 *
 * space_get_west gets the west id of a space
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space whose west id we want to get
 * @return the west id of the space
 */
Id space_get_west(Space* space);

/**
 * @brief Adds an object in a space
 *
 * space_set_object changes the object id of a space
 *
 * @date 27-02-2020
 * @author Evangelos Lazarakis
 *
 * @param space  is the space that we want to add an object in
 * @param id is the id of the new object of the space
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_add_object(Space* space, Id object);

/**
 * @brief Deletes an object from a space
 *
 * space_set_object changes the object id of a space
 *
 * @date 27-02-2020
 * @author Evangelos Lazarakis
 *
 * @param space  is the space that we want to remove an object from
 * @param id is the id of object we want to delete
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_del_object(Space* space, Id object);

/**
 * @brief Informs if an object Id is in a space
 *
 * @date 27-02-2020
 * @author Evangelos Lazarakis
 *
 * @param space the space we want to check if it contains an object Id
 * @param id the object id we want to search for
 * @return TRUE if the Id is in the space, FALSE otherwise
 */
BOOL space_contain_object(Space* space, Id id);

/**
 * @brief Gets the Object Id in a certain position in the ids array
 *
 * @author Evangelos Lazarakis
 * @date 07-03-2020
 *
 * @param space the space from which we want an Id
 * @param position the position in the ids array whose id will be returned
 * @return the Object Id of the specific position in the ids array
 */
Id space_get_id_at(Space* space, int position);

/**
 * @brief Gets the number of objects in the space
 *
 *
 * @date 03-03-2020
 * @author Evangelos Lazarakis
 *
 * @param space the space whose number of objects will be returned
 * @return the number of objects of the space
 */
int space_get_n_objects(Space* space);

/**
 * @brief Sets a line of the graphic description of a space
 *
 * space_set_graphics sets a line in the graphic description of a space
 *
 * @date 05-03-2020
 * @author Evangelos Lazarakis
 *
 * @param space  is the space whose graphic description we want to set
 * @param graphics  is the new line in the graphic description of the space
 * @param line   is the line which in the graphic description which we want to set
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_set_graphics_line(Space* space, char* graphics, int line);

/**
 * @brief Gets a line from the graphic description of a space
 *
 * space_get_graphics gets a line from the graphic description of a space
 *
 * @date 05-03-2020
 * @author Evangelos Lazarakis
 *
 * @param space  is the space whose graphic description we want to get
 * @param line  is the # of the line which we want to get
 * @return a line from the graphic description of the space
 */
char* space_get_graphics_line(Space* space, int line);

/**
 * @brief Sets the description of the space
 *
 * Gets a string as input and sets it as the space's description
 *
 * @date 05-04-2020
 * @author Evangelos Lazarakis
 *
 * @param space the space whose description will change
 * @param desc the new description of the space
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_set_description(Space* space, char* desc);

/**
 * @brief Gets the description of the space
 *
 * Returns a space's description
 *
 * @date 05-04-2020
 * @author Evangelos Lazarakis
 *
 * @param space the space whose description will be returned
 * @return a string with the space's description
 */
char* space_get_description(Space* space);

/**
 * @brief Sets if the space is illuminatable
 *
 * Gets a BOOL as input and sets it as the space's illuminate state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param space the space whose illuminate state will change
 * @param move the illuminate state of the space
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_set_illuminate(Space* space, BOOL illuminate);

/**
 * @brief Gets the illuminate state of the space
 *
 * Gets an space as input and returns it's illuminate state
 *
 * @date 05-05-2020
 * @author Evangelos Lazarakis
 *
 * @param space the space whose illuminate state will be returned
 * @return a BOOL with the space's illuminate state
 */
BOOL space_get_illuminate(Space* space);

/**
 * @brief Prints the data of a space
 *
 * space_print prints all of a space's information
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param space  is the space whose data we want to print
 * @return a STATUS code, ERROR in case of an error or OK
 */
STATUS space_print(Space* space);

#endif
