/**
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 19-12-2014
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2           //Number of command types
#define N_CMD 15           //Number of commands

typedef enum enum_CmdType {CMDS, CMDL} T_CmdType;           //An enumeration for the command types

typedef enum enum_Command {NO_CMD = -1, UNKNOWN, EXIT, NEXT, BACK, TAKE, DROP, ROLL, LEFT, RIGHT, MOVE, INSPECT, TURNON, TURNOFF, OPEN} T_Command;           //An enumeration for all the commands

/**
 * @brief Gets command the user wants to execute
 *
 * Gets the user's input and returns the command he wants to execute
 *
 * @author Profesores PPROG
 * @date 19-12-2014
 *
 * @return the command that the user wants to execute
 */

T_Command command_get_user_input();

#endif
