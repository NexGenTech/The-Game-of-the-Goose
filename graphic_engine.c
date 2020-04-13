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

  ge->map      = screen_area_init( 1, 1, 48, 22);  //height (parameter 4) +9
  ge->descript = screen_area_init(50, 1, 29, 22);  //height (parameter 4) +9
  ge->banner   = screen_area_init(28,24, 23,  1);  //y (parameter 2)+9
  ge->help     = screen_area_init( 1,25, 78,  3);  //y (parameter 2)+9,height (parameter 4) +1
  ge->feedback = screen_area_init( 1,29, 78,  2);  //y (parameter 2)+10,

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
  char str[255];                //just a variable used for printing
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
    /*if (game_get_object_location(game) == id_back)
      obj='*';
    else
      obj=' ';*/

    if (id_back != NO_ID) {
      sprintf(str, "  |         %2d|",(int) id_back);
      screen_area_puts(ge->map, str);
      for(int i = 0; i <= 2; i++){
        strcpy(line, space_get_graphics_line(game_get_space(game, id_back),i));
        sprintf(str, "  |%s    |", line);
        screen_area_puts(ge->map, str);
      }

      char dummie[255];
      int n_objects = space_get_n_objects(game_get_space(game,id_back));
      strcpy(str,"  |");
      if(n_objects > 0){
        for(int i = 0; i < n_objects ; i++){
          sprintf(dummie, "%s,", object_get_name(game_get_object(game, space_get_id_at(game_get_space(game,id_back),i))));
          strcat(str,dummie);
        }
      }
      if (strlen(str) < 14 ){
        int loops = strlen(str);
        for(int i = 0; i < 14 - loops ; i++){
          strcat(str," ");
        }
      }
      strcat(str,"|");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    /*if (game_get_object_location(game) == id_act)
      obj='*';
    else
      obj=' ';*/

    if (id_act != NO_ID) {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | 8D      %2d|",(int) id_act);
      screen_area_puts(ge->map, str);
      for(int i = 0; i <= 2; i++){
        strcpy(line, space_get_graphics_line(game_get_space(game, id_act),i));
        sprintf(str, "  |%s    |", line);
        screen_area_puts(ge->map, str);
      }

      char dummie[255];
      int n_objects = space_get_n_objects(game_get_space(game,id_act));
      strcpy(str,"  |");
      if(n_objects > 0){
        for(int i = 0; i < n_objects ; i++){
          sprintf(dummie, "%s,", object_get_name(game_get_object(game, space_get_id_at(game_get_space(game,id_act),i))));
          strcat(str,dummie);
        }
      }
      if (strlen(str) < 14 ){
        int loops = strlen(str);
        for(int i = 0; i < 14 - loops ; i++){
          strcat(str," ");
        }
      }
      strcat(str,"|");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    /*if (game_get_object_location(game) == id_next)
      obj='*';
    else
      obj=' ';*/

    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|",(int) id_next);
      screen_area_puts(ge->map, str);
      for(int i = 0; i <= 2; i++){
        strcpy(line, space_get_graphics_line(game_get_space(game, id_next),i));
        sprintf(str, "  |%s    |", line);
        screen_area_puts(ge->map, str);
      }
      char dummie[255];
      int n_objects = space_get_n_objects(game_get_space(game,id_next));
      strcpy(str,"  |");
      if(n_objects > 0){
        for(int i = 0; i < n_objects ; i++){
          sprintf(dummie, "%s,", object_get_name(game_get_object(game,space_get_id_at(game_get_space(game,id_next),i))));
          strcat(str,dummie);
        }
      }
      if (strlen(str) < 14 ){
        int loops = strlen(str);
        for(int i = 0; i < 14 - loops ; i++){
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

  /*sprintf(str,"\n");
  screen_area_puts(ge->descript, str);*/

  for(int i = 0; i < n_objects ; i++) {
    if ((player_obj = player_search_object(game_get_player(game), object_get_id(game_get_object_at(game, i)))) != NO_ID){
      sprintf(str, " Player object: %s", object_get_name(game_get_object(game,player_obj)));
      screen_area_puts(ge->descript, str);
      sprintf(str, " ");
      screen_area_puts(ge->descript, str);
    }
  }

  /*sprintf(str,"\n");
  screen_area_puts(ge->descript, str);*/

  if ((last_die = die_get_last_roll(game_get_die(game))) != -1){
    sprintf(str, " Last die value: %d",last_die);
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
  sprintf(str, "     next or n, back or b, exit or e, take or t, drop or d, roll or rl, right or r, left or l, move or m, inspect or i");
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
