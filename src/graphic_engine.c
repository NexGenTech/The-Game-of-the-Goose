/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 18-01-2017
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphic_engine.h"
#include "command.h"


typedef struct _Graphic_engine{
  Area *map, *descript, *banner, *help, *feedback;
}Graphic_engine;


Graphic_engine *graphic_engine_create(){
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

  ge->map      = screen_area_init( 1, 1, 58, 22);
  ge->descript = screen_area_init(60, 1, 39, 22);
  ge->banner   = screen_area_init(38,24, 23,  1);
  ge->help     = screen_area_init( 1,25, 98,  3);
  ge->feedback = screen_area_init( 1,29, 98,  2);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge){
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game game){
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID, player_obj = NO_ID;
  int last_die = -1;
  Space* space_act = NULL;
  char line[WORD_SIZE] = "";
  char last_desc[WORD_SIZE] = "";
  char str[255];                     //just a variable used for printing
  char dummie1[255] = "";            //just a variable used for printing
  char dummie2[255] = "";            //just a variable used for printing
  T_Command last_cmd = UNKNOWN; // Holds the value of the last command executed
  char status[WORD_SIZE] = "";  // Holds the status of the outcome of the last command executed

  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){

    space_act = game_get_space(game, id_act);
    if(space_get_north(space_act) != NO_ID) {
      id_back = link_get_other(game_get_link(game, space_get_north(space_act)), id_act);
    }
    if(space_get_south(space_act) != NO_ID) {
      id_next = link_get_other(game_get_link(game, space_get_south(space_act)), id_act);
    }


    if (id_back != NO_ID) {
      sprintf(str, "         |               %2d|",(int) id_back);
      screen_area_puts(ge->map, str);
      for(int i = 0; i <= 2; i++){
        strcpy(line, space_get_graphics_line(game_get_space(game, id_back),i));
        sprintf(str, "         |   %s       |", line);
        screen_area_puts(ge->map, str);
      }

      char dummie[255];
      int n_objects = space_get_n_objects(game_get_space(game,id_back));
      strcpy(str,"         |");
      if(n_objects > 0){
        for(int i = 0; i < n_objects ; i++){
          sprintf(dummie, "%s,", object_get_name(game_get_object(game, space_get_id_at(game_get_space(game,id_back),i))));
          strcat(str,dummie);
        }
      }
      if (strlen(str) < 27 ){
        int loops = strlen(str);
        for(int i = 0; i < 27 - loops ; i++){
          strcat(str," ");
        }
      }
      strcat(str,"|");
      screen_area_puts(ge->map, str);
      sprintf(str, "         +-----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                  ^ %ld", space_get_north(space_act));
      screen_area_puts(ge->map, str);
    }


    if (id_act != NO_ID) {
      sprintf(str,"      ");
      if(space_get_west(space_act) != NO_ID) {
        char west[255];
        sprintf(west, "%2ld", space_get_west(space_act));
        strcat(str, west);
      } else {
        strcat(str, "  ");
      }
      strcat(str, " +-----------------+ ");
      if(space_get_east(space_act) != NO_ID) {
        char east[255];
        sprintf(east, "%2ld", space_get_east(space_act));
        strcat(str, east);
      }
      screen_area_puts(ge->map, str);

      sprintf(str,"   ");
      if(space_get_west(space_act) != NO_ID) {
        char west[255];
        sprintf(west, "%ld <--", link_get_other(game_get_link(game,space_get_west(space_act)), id_act));
        strcat(str, west);
      } else {
        strcat(str, "     ");
      }
      sprintf(dummie1, " | 8D            %2d| ",(int) id_act);
      strcat(str, dummie1);
      if(space_get_east(space_act) != NO_ID) {
        char east[255];
        sprintf(east, "--> %ld", link_get_other(game_get_link(game,space_get_east(space_act)), id_act));
        strcat(str, east);
      }
      screen_area_puts(ge->map, str);
      for(int i = 0; i <= 2; i++){
        strcpy(line, space_get_graphics_line(game_get_space(game, id_act),i));
        sprintf(str, "         |   %s       |", line);
        screen_area_puts(ge->map, str);
      }

      char dummie[255];
      int n_objects = space_get_n_objects(game_get_space(game,id_act));
      strcpy(str,"         |");
      if(n_objects > 0){
        for(int i = 0; i < n_objects ; i++){
          sprintf(dummie, "%s,", object_get_name(game_get_object(game, space_get_id_at(game_get_space(game,id_act),i))));
          strcat(str,dummie);
        }
      }
      if (strlen(str) < 27 ){
        int loops = strlen(str);
        for(int i = 0; i < 27 - loops ; i++){
          strcat(str," ");
        }
      }
      strcat(str,"|");
      screen_area_puts(ge->map, str);
      sprintf(str, "         +-----------------+");
      screen_area_puts(ge->map, str);
    }


    if (id_next != NO_ID) {
      Space* space_next = game_get_space(game, link_get_other(game_get_link(game, space_get_south(space_act)), id_act));
      sprintf(str, "                  v %ld", space_get_south(space_act));
      screen_area_puts(ge->map, str);
      sprintf(str,"      ");
      if(space_get_west(space_next) != NO_ID) {
        char west[255];
        sprintf(west, "%2ld", space_get_west(space_next));
        strcat(str, west);
      } else {
        strcat(str, "  ");
      }
      strcat(str, " +-----------------+ ");
      if(space_get_east(space_next) != NO_ID) {
        char east[255];
        sprintf(east, "%2ld", space_get_east(space_next));
        strcat(str, east);
      }
      screen_area_puts(ge->map, str);

      sprintf(str,"   ");
      if(space_get_west(space_next) != NO_ID) {
        char west[255];
        sprintf(west, "%ld <--", link_get_other(game_get_link(game,space_get_west(space_next)), id_next));
        strcat(str, west);
      } else {
        strcat(str, "     ");
      }
      sprintf(dummie1, " |               %2d| ",(int) id_next);
      strcat(str, dummie1);
      if(space_get_east(space_next) != NO_ID) {
        char east[255];
        sprintf(east, "--> %ld", link_get_other(game_get_link(game,space_get_east(space_next)), id_next));
        strcat(str, east);
      }
      screen_area_puts(ge->map, str);

      for(int i = 0; i <= 2; i++){
        strcpy(line, space_get_graphics_line(game_get_space(game, id_next),i));
        sprintf(str, "         |   %s       |", line);
        screen_area_puts(ge->map, str);
      }
      char dummie[255];
      int n_objects = space_get_n_objects(game_get_space(game,id_next));
      strcpy(str,"         |");
      if(n_objects > 0){
        for(int i = 0; i < n_objects ; i++){
          sprintf(dummie, "%s,", object_get_name(game_get_object(game,space_get_id_at(game_get_space(game,id_next),i))));
          strcat(str,dummie);
        }
      }
      if (strlen(str) < 27 ){
        int loops = strlen(str);
        for(int i = 0; i < 27 - loops ; i++){
          strcat(str," ");
        }
      }
      strcat(str,"|");
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint the in the description area */
  screen_area_clear(ge->descript);
  int n_objects = game_get_n_objects(game);
  sprintf(str, "  Objects location:");
  screen_area_puts(ge->descript, str);

  for(int i = 0; i < n_objects ; i++){
    Object* object = game_get_object_at(game,i);
    Id object_id = object_get_id(object);
    if ((obj_loc = game_get_object_location(game,object_id)) != NO_ID){
      sprintf(dummie1, "  %s:%ld,",object_get_name(object), obj_loc);
      strcat(dummie2,dummie1);
    }
  }
  strcpy(str, dummie2);
  screen_area_puts(ge->descript, str);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);


  for(int i = 0; i < n_objects ; i++) {
    if ((player_obj = player_search_object(game_get_player(game), object_get_id(game_get_object_at(game, i)))) != NO_ID){
      sprintf(str, " Player object: %s", object_get_name(game_get_object(game,player_obj)));
      screen_area_puts(ge->descript, str);
      sprintf(str, " ");
      screen_area_puts(ge->descript, str);
    }
  }


  if ((last_die = die_get_last_roll(game_get_die(game))) != -1){
    sprintf(str, " Last die value: %d",last_die);
    screen_area_puts(ge->descript, str);
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
  }

  strcpy(last_desc, game_get_last_description(game));
  if((strlen(last_desc)) != 0) {
    sprintf(str, " Description:");
    screen_area_puts(ge->descript, str);
    sprintf(str, " %s", last_desc);
    screen_area_puts(ge->descript, str);
    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
  }

  /* Paint the in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, take or t, drop or d, roll or rl, right or r, left or l, move or m, inspect or i, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  last_cmd = game_get_last_command(game);
  if (game_get_last_command_status(game) == OK){
    strcpy(status,"OK");
  } else {
    strcpy(status,"ERROR");
  }
  sprintf(str, " %s (%s) : %s", cmd_to_str[last_cmd-NO_CMD][CMDL], cmd_to_str[last_cmd-NO_CMD][CMDS], status);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
