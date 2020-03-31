/**
 * @brief It declares the set struct
 *
 *@file set.c
 *@author Evangelos Lazarakis
 *@date 18/02/2020
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "link.h"

typedef struct _Link {
  Id id;
  char name[WORD_SIZE + 1];
  Id space_one;
  Id space_two;
  LINK_STATUS status;
} Link;

Link* link_create(Id id) {
  Link* newlink = NULL;

  newlink = malloc(sizeof(Link));

  if (newlink == NULL) {
    return NULL;
  }

  newlink->id = id;
  newlink->name[0] = '\0';
  newlink->space_one = NO_ID;
  newlink->space_two = NO_ID;
  newlink->status = CLOSED;

  return newlink;
}

STATUS link_destroy(Link* link) {
  if(!link) {
    return ERROR;
  }

  free(link);

  return OK;
}

STATUS link_set_name(Link* link, char* name) {
  if(!link || !name) {
    return ERROR;
  }

  if (!(strcpy(link->name, name))) {
    return ERROR;
  }

  return OK;
}

const char * link_get_name(Link* link) {
  if (!link) {
    return NULL;
  }
  return link->name;
}

Id link_get_id(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->id;
}

LINK_STATUS link_get_status(Link* link) {
  return link->status;
}

STATUS link_set_status(Link* link, LINK_STATUS status) {
  if(!link) {
    return ERROR;
  }

  if (!(link->status = status)) {
    return ERROR;
  }

  return OK;
}

Id link_get_space_one_id(Link* link) {
  return link->space_one;
}

Id link_get_space_two_id(Link* link) {
  return link->space_two;
}

STATUS link_set_space_one_id(Link* link, Id id) {
  if(!link) {
    return ERROR;
  }

  if (!(link->space_one = id)) {
    return ERROR;
  }

  return OK;
}

STATUS link_set_space_two_id(Link* link, Id id) {
  if(!link) {
    return ERROR;
  }

  if (!(link->space_two = id)) {
    return ERROR;
  }

  return OK;
}

STATUS link_print(Link* link) {
  if(!link) {
    return ERROR;
  }

  printf("Link :\n  Id: %ld\n  Name: %s\n  Space Id #1: %ld\n  Space Id #2: %ld\n  ",
  link->id, link->name, link->space_one, link->space_two);

  if (link->status == OPEN) {
    printf("OPEN\n\n");
  } else {
    printf("CLOSED\n\n");
  }

  return OK;
}
