#include <stdio.h>
#include "player.h"
#include "inventory.h"

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

  printf("This is the end of the player test\n");

  return 0;
}
