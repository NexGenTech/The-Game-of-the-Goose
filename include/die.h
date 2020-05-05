/**
 * @brief It declares the Die structure
 *
 * @file die.h
 * @author Evangelos Lazarakis
 * @version 1.0
 * @date 25/02/2020
 */

 #ifndef DIE_H
 #define DIE_H

 #include "types.h"

 /**
  * @brief the Die structure
  * Stores the data of the Die
  */
 typedef struct _Die Die;

 /**
  * @brief Creates a die
  *
  * Gets an Id, a min value and a max value nad returns a pointer to a die
  *
  * @author Evangelos Lazarakis
  * @date 25-02-2020
  *
  * @param id the id that the new die is going to have
  * @param min the minimum value that the die can take
  * @param max the maximum value that the die can take
  * @return a pointer to the new die
  */
 Die* die_create(Id id, int min, int max);

 /**
  * @brief Destroys a die struct
  *
  * Gets a die as input and deallocates it's memory
  *
  * @author Evangelos Lazarakis
  * @date 25-02-2020
  *
  * @param die the die that is going to be destroyed
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS die_destroy(Die* die);

 /**
  * @brief Set the last roll of a die
  *
  * Gets a die pointer and the last_roll value and updates the die
  *
  * @author Evangelos Lazarakis
  * @date 25-02-2020
  *
  * @param die the die whose last roll is going to be changed
  * @param last_roll  the value of the die's last roll
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS die_set_last_roll(Die* die, int last_roll);

 /**
  * @brief Get the last roll of a die
  *
  * Gets a die pointer as input and returns it's last_roll value
  *
  * @author Evangelos Lazarakis
  * @date 25-02-2020
  *
  * @param die the die whose last roll is going to be returned
  * @return the last roll of the die
  */
 int die_get_last_roll(Die* die);

/**
 * @brief Roll the die
 *
 * Gets a die pointer as input, rolls it and updates it's last_roll value
 *
 * @author Evangelos Lazarakis
 * @date 25-02-2020
 *
 * @param die  the die that is going to be rolled
 * @return a STATUS code, ERROR if any error occures or OK
 */
 STATUS die_roll(Die* die);

 /**
  * @brief Print the data of a die
  *
  * Gets a die pointer as input and prints all it's fields
  *
  * @author Evangelos Lazarakis
  * @date 25-02-2020
  *
  * @param die the die whose data is going to be printed
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS die_print(Die* die);

#endif
