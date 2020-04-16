/**
 * @brief It tests the link module
 *
 *@file die_test.c
 *@author Evangelos Lazarakis
 *@date 18/03/2020
 *
 */
#include <stdio.h>
#include "link.h"

int main(void) {
  printf("This is the begining of the link test..\n\n");

  Id space_one = 10, space_two = 15, link_id = 100;
  char name[] = "Peter";
  Link* link = link_create(link_id);


  link_set_name(link,name);
  link_set_space_one_id(link,space_one);
  link_set_space_two_id(link, space_two);
  link_set_status(link,OPEN);

  link_print(link);

  link_destroy(link);

  printf("This is the end of the link test..\n\n");

  return 0;

}
