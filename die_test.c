/**
 * @brief It tests the die module
 *
 *@file die_test.c
 *@author Evangelos Lazarakis
 *@date 18/02/2020
 *
 */

 #include <stdio.h>
 #include "die.h"

int main(void){

  printf("This is the start of the die test\n");

  Die* die = die_create(1);

  die_roll(die);

  printf("The die's last roll was %d\n",die_get_last_roll(die) );

  die_print(die);

  die_destroy(die);

  printf("This is the end of the die test\n");

  return(0);
}