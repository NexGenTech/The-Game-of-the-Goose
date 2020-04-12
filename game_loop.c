/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"

/**
 * @brief Initialize the game loop
 *
 * game_loop_init will initianlize the Game and Graphic_engine
 * structs to run the game loop
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param gengine  the Graphic_engine struct to be initialized
 * @param file_name  the file that contains the game board
 * @return the created Game
 */
Game game_loop_init(Graphic_engine **gengine, char *file_name);

/**
 * @brief Runs the game loop
 *
 * game_loop_run will run the game loop until the game ends
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param game  the Game struct that holds the game's data
 * @param gengine  the Graphic_engine struct that holds game's data to be printed
 */
void game_loop_run(Game game, Graphic_engine *gengine, FILE* file);

/**
 * @brief Terminates the game loop
 *
 * game_loop_cleanup will destroy the game and the Graphic_engine
 *
 * @date 13-01-2015
 * @author Profesores PPROG
 *
 * @param game  the Game struct to be destroyed
 * @param gengine  the Graphic_engine struct to be destroyed
 */
void game_loop_cleanup(Game game, Graphic_engine *gengine);


int main(int argc, char *argv[]) {
  Game game;
  Graphic_engine *gengine;
  FILE* file = NULL;

  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  if ((argc < 4) && (argc > 2)) {
    fprintf(stderr, "Wrong number of arguments\n" );
    return 1;
  }

  if (argc == 4) {
    if (strcmp(argv[2],"-l") == 0) {
      if (strcmp(argv[3],"LOG") == 0) {
        file = fopen(argv[3],"w");
      } else {
        fprintf(stderr, "Wrong arguments\n" );
        return 1;
      }
    } else {
      fprintf(stderr, "Wrong arguments\n" );
      return 1;
    }
  }

  if ((game = game_loop_init(&gengine, argv[1])) != NULL){
    game_loop_run(game, gengine, file);
    game_loop_cleanup(game, gengine);
  }

  if (file != NULL){
    fclose(file);
  }

  return 0;
}

Game game_loop_init(Graphic_engine **gengine, char *file_name){
  Game game;
  if ((game = game_create_from_file(file_name)) == ERROR) {
    fprintf(stderr, "Error while initializing game.\n");
    return NULL;
  }

  if ((*gengine = graphic_engine_create()) == NULL) {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return NULL;
  }

  return game;
}

void game_loop_run(Game game, Graphic_engine *gengine, FILE* file){
  extern char *cmd_to_str[N_CMD][N_CMDT];
  T_Command command = NO_CMD;

  while ((command != EXIT) && !game_is_over(game)) {
    graphic_engine_paint_game(gengine, game);
    command = command_get_user_input();
    game_update(game, command);

    if (file != NULL) {
      char status[255] = "";
      T_Command last_cmd = game_get_last_command(game);
      if (game_get_last_command_status(game) == OK){
        strcpy(status,"OK");
      } else {
        strcpy(status,"ERROR");
      }

      fprintf(file, " %s (%s) : %s\n", cmd_to_str[last_cmd-NO_CMD][CMDL], cmd_to_str[last_cmd-NO_CMD][CMDS], status);
    }
  }
}

void game_loop_cleanup(Game game, Graphic_engine *gengine){
  game_destroy(game);
  graphic_engine_destroy(gengine);
}
