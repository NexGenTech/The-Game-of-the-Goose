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
 typedef struct _Die{
    Id id;
    int min;
    int max;
    int last_roll;
 }Die;

 /**
  * @brief Creates a die struct with the Id that is given as input
  *
  * @author Evangelos Lazarakis
  * @date 25-02-2020
  *
  * @param id the id that the new die is going to have
  * @return a pointer to the new die
  */
 Die* die_create(Id id);

 /**
  * @brief Deatroys a die struct
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
  * @author Evangelos Lazarakis
  * @date 25-02-2020
  *
  * @param die the die whose last roll is going to be changed
  * @param last_roll  the value of the die's last roll
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS die_set_last_roll(Die* die, int last_roll);

 /**
  * @brief Set the last roll of a die
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
  * @author Evangelos Lazarakis
  * @date 25-02-2020
  *
  * @param die the die whose data is going to be printed
  * @return a STATUS code, ERROR if any error occures or OK
  */
 STATUS die_print(Die* die);

#endif