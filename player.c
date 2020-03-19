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
  Id id;            // The Id of the player
  char name[WORD_SIZE + 1]; // The name of the player
  Id location;        // The Id of the space that the player is on
  Id object;          // The id of the object that the player is currently holding
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

  newplayer->object = NO_ID;
  
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

STATUS player_set_object(Player* player, Id object) {
  if (!player) {
    return ERROR;
  }

  if (!(player->object = object)) {
    return ERROR;
  }

  return OK;
}

Id player_get_object(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->object;
}

void player_print(Player* player){

  printf("The player with id %ld has : \n name -> %s\n location id -> %ld\n object id -> %ld\n",player->id,player->name,player->location,player->object);
}