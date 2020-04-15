/**
 * @brief It tests the space module
 *
 *@file die_test.c
 *@author Evangelos Lazarakis
 *@date 15/04/2020
 *
 */

 #include <stdio.h>
 #include "space.h"

 int main(void) {
   printf("This is the start of the space test\n");


   Space* space = space_create(1);
   space_set_name(space, "Nameless Space!!!");
   space_set_east(space, 2);
   space_set_west(space, 3);
   space_set_north(space, 5);
   space_set_south(space, 10);
   for(int i = 0; i < 3; i++){
     space_set_graphics_line(space, "-------", i);
   }
   space_set_description(space, "Nothing much");

   space_add_object(space, 15);

   space_print(space);


   printf("This is the end of the space test\n");

 }
