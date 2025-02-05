/**
 * @brief It implements the Die structure
 *
 * @file die.c
 * @author Evangelos Lazarakis
 * @version 1.0
 * @date 25/02/2020
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include "die.h"

 typedef struct _Die{
    Id id;
    int min;
    int max;
    int last_roll;
 }Die;

Die* die_create(Id id, int min, int max){

  Die *newDie = NULL;

  newDie = (Die *) malloc(sizeof (Die));

  if (newDie == NULL) {
    return NULL;
  }

  newDie->id = id;

  newDie->min = min;

  newDie->max = max;

  newDie->last_roll = -1;

  srand(time(0));

  return newDie;
 }

STATUS die_destroy(Die* die) {
  if (!die) {
    return ERROR;
  }

  free(die);
  die = NULL;

  return OK;
 }

STATUS die_set_last_roll(Die* die, int last_roll) {
  if (!die || !last_roll) {
    return ERROR;
  }

  if (!(die->last_roll = last_roll)) {
    return ERROR;
  }

  return OK;
 }

 int die_get_last_roll(Die* die) {

  return die->last_roll;
 }

STATUS die_roll(Die* die){

  int roll = (rand() % (die->max - die->min + 1)) + die->min;

  die_set_last_roll(die,roll);

  return roll;
 }

STATUS die_print(Die* die){

  if(!die){
    return ERROR;
  }

  printf("The die with id %ld has : \n min value -> %d\n min value -> %d\n Last roll id -> %d\n",die->id,die->min,die->max,die->last_roll);

  return OK;
 }
