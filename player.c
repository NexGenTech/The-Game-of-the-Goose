/**
 * @brief It implements the player struct and all
 * of its functions
 *
 * @file player.c
 * @author Evangelos Lazarakis
 * @version 1.0
 * @date 10-02-2020
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"


typedef struct _Player{
  Id id;                       // The Id of the player
  char name[WORD_SIZE + 1];    // The name of the player
  Id location;                 // The Id of the space that the player is on
  Inventory* backpack;         // It will hold the objects of the player
}Player;

Player* player_create(Id id){

  Player *newplayer = NULL;

  newplayer = (Player *) malloc(sizeof (Player));

  if (newplayer == NULL) {
    return NULL;
  }

  newplayer->id = id;

  newplayer->name[0] = '\0';

  newplayer->location = NO_ID;

  newplayer->backpack = inventory_create();

  return newplayer;
}

STATUS player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}

Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

STATUS player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}

const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

STATUS player_set_location(Player* player, Id location) {

  if (!player) {
    return ERROR;
  }

  if (!(player->location = location)) {
    return ERROR;
  }

  return OK;
}

Id player_get_location(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->location;
}

STATUS player_add_object(Player* player, Id object) {
  if (!player) {
    return ERROR;
  }

  if (!(inventory_add_object(player->backpack, object))) {
    return ERROR;
  }

  return OK;
}

STATUS player_del_object(Player* player,Id object) {
  if (!player) {
    return ERROR;
  }

  if (!(inventory_del_object(player->backpack, object))) {
    return ERROR;
  }

  return OK;
}

Id player_search_object(Player* player, Id object) {
  return inventory_search_object(player->backpack, object);
}


STATUS player_set_backpack_size(Player* player, int size) {
  if (!player) {
    return ERROR;
  }

  if (!(inventory_set_max_objects(player->backpack, size))) {
    return ERROR;
  }

  return OK;
}

STATUS player_backpack_has_space(Player* player) {
  return inventory_has_space(player->backpack);
}

void player_print(Player* player){

  printf("The player with id %ld has : \n name -> %s\n location id -> %ld\n object ids : \n",player->id,player->name,player->location);
  int i = 0;
  for(Id id = inventory_get_object_at(player->backpack, i); id != NO_ID; id = inventory_get_object_at(player->backpack, ++i)) {
    printf("    ->%ld\n",id);
  }
}
