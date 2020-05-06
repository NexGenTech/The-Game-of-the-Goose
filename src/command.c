/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30           //The maximum length of the string of each command

//A matrix with all the possible commands
char *cmd_to_str[N_CMD][N_CMDT] = {{"","No command"}, {"","Unknown"},{"e","Exit"}, {"n","Next"}, {"b","Back"},
{"t","Take"}, {"d","Drop"}, {"rl","Roll"}, {"l","Left"}, {"r","Right"}, {"m","Move"}, {"i","Inspect"},
{"turnon", "Turnon"}, {"turnoff", "Turnoff"}, {"o", "Open"}, {"save", "Save"}, {"load", "Load"}};

T_Command command_get_user_input(){

  T_Command cmd = NO_CMD;       // The command that will be returned
  char input[CMD_LENGHT] = "";  // Used to collect the user input
  int i= UNKNOWN - NO_CMD + 1;  // Just a counter to go through cmd_to_str


  if (scanf("%s", input) > 0)  {          // Runs through the whole cmd_to_str matrix to determine if input maches any of the commands
    cmd = UNKNOWN;                        // If not, then UNKNOWN command is returned
    while (cmd == UNKNOWN && i < N_CMD){
      if (!strcasecmp(input, cmd_to_str[i][CMDS])|| !strcasecmp(input, cmd_to_str[i][CMDL])){
        cmd = i + NO_CMD;
      } else {
        i++;
      }
    }
  }

  return cmd;
}
