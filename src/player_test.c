/**
 * @brief It tests the player module
 *
 *@file die_test.c
 *@author Evangelos Lazarakis
 *@date 18/03/2020
 *
 */

#include <stdio.h>
#include "player.h"

int main(void) {
  printf("This is the start of the player test\n");
  Player* player = player_create(10);
  char* name = "Christina";
  Id location = 35;
  int size = 20;

  player_set_name(player, name);
  player_set_location(player, location);
  player_set_backpack_size(player, size);

  player_print(player);

  printf("Adding 23 objects to the player's backpack\n");
  for(Id id = 1; id <= 23; id++) {
    player_add_object(player, id);
  }
  player_print(player);

  printf("\nOnly the first 20 objects were actually added to the backpack cause its max capacity is 20\n\n\n");

  if (player_backpack_has_space(player)) {
    printf("The player's backpack still has some spare space\n");
  } else {
    printf("The player's backpack is full\n");
  }

  printf("Now the odd-number objects will be deleted from the backpack\n\n");

  for (Id id = 1; id <= 20; id+=2) {
    player_del_object(player, id);
  }

  player_print(player);

  if (player_backpack_has_space(player)) {
    printf("The player's backpack still has some spare space\n");
  } else {
    printf("The player's backpack is full\n");
  }

  Id id = 7;
  if(player_search_object(player, id) == id) {
    printf("\nThe object with id %ld exists in the backpack\n",id );
  } else {
    printf("\nThe object with id %ld does not exist in the backpack\n",id );
  }

  id = 10;
  if(player_search_object(player, id) == id) {
    printf("\nThe object with id %ld exists in the backpack\n",id );
  } else {
    printf("The object with id %ld does not exist in the backpack\n",id );
  }
  printf("\nThis is the end of the player test\n");

  return 0;
}
