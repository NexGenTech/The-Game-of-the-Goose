/**
 * @brief It declares the set struct
 *
 *@file set.c
 *@author Evangelos Lazarakis
 *@date 18/02/2020
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

typedef struct _Set{
   Id ids[MAX_CAPACITY + 1];           // An array of Ids
   int n_ids;                          // The number of Ids that are currently in the array
}Set;

Set* set_create(){

  Set* newSet = NULL;

  newSet = (Set*) malloc(sizeof (Set));
  
  if (newSet == NULL) {
    return NULL;
  }

  int i;
  for(i=0 ; i <= MAX_CAPACITY ; i++){
    newSet->ids[i] = NO_ID;           //By initializing the whole set with the NO_ID value means that it expects
  }                                   //that there will be no objects initialized with a NO_ID value

  newSet->n_ids = 0;

  return newSet;
}

STATUS set_destroy(Set* set) {
  if (!set) {
    return ERROR;
  }

  free(set);
  set = NULL;

  return OK;
}

STATUS set_add(Set *set, Id id){

  if(!set){
    return ERROR;
  }

  int n_ids = set_get_n_ids(set);

  set->ids[n_ids] = id;
  set->n_ids += 1;

  return OK;
}

STATUS set_del(Set* set, Id id){

  if(!set){
    return ERROR;
  }

  int pos = -1, i;

  for(i=0 ; pos == -1 ; i++){   //Search for the Id's position in the set in order to delete it
    if(set->ids[i] == id){
      pos = i;
    }
  }

  if(pos == -1){      //if pos equals -1, then the id does not exist in the set
    return ERROR;
  }

  int n_ids = set_get_n_ids(set);
  set->ids[pos] = set->ids[n_ids - 1];    //Put at the position of the Id we want to delete the Id which is at the end of the set

  set->ids[n_ids - 1] = NO_ID;

  set->n_ids -= 1;

  return OK;
}

Id set_search_id(Set* set, Id id){

  int i, n_ids = set_get_n_ids(set);

  for(i=0 ; i < n_ids ; i++){
    if(set->ids[i] == id){
      return id;}
  }

  return NO_ID;
}

int set_get_n_ids(Set* set){

  return set->n_ids;
}

STATUS set_print(Set* set){

  if(!set){
    return ERROR;
  }

  int i, n_ids = set_get_n_ids(set);

  printf("Printing a Set with %d Ids :\n",n_ids);

  for(i=0 ; i<= n_ids -1 ; i++){
    printf("\t%ld\n",set->ids[i]);
  }


  return OK;
}

Id set_get_id_at(Set* set, int position) {

  if (position < 0 || position >= MAX_CAPACITY) {
    return NO_ID;
  }
  return set->ids[position];
}
