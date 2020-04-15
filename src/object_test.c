/**
 * @brief It tests the object module
 *
 *@file die_test.c
 *@author Evangelos Lazarakis
 *@date 15/04/2020
 *
 */

 #include <stdio.h>
 #include "object.h"

 int main(void) {
   printf("This is the start of the object test\n");

   Object* object = object_create(1);
   object_set_name(object, "RANDOM");
   object_set_description(object, "Something random");

   object_print(object);

   printf("This is the end of the object test\n");

 }
