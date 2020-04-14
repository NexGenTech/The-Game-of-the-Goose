/**
 * @brief It defines common types
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000       // It is the word size that is going to be used for every string
#define NO_ID -1             // This is the Id for every struct that currently does not have an Id

typedef long Id;

typedef enum {               // An enumeration for true and false
  FALSE, TRUE
} BOOL;

typedef enum {               // An enumeration for the status of a function
  ERROR, OK
} STATUS;

typedef enum {               // An enumeration for determining the direction
  N, S, E, W
} DIRECTION;

#endif
