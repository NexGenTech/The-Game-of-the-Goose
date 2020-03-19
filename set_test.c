/**
 * @brief It tests the set module
 *
 *@file set_test.c
 *@author Evangelos Lazarakis
 *@date 18/02/2020
 *
 */

#include <stdio.h>
#include "set.h"

int main(void){

	printf("This is the start of the set_test\n");


	Set* set = set_create();

	int i;

	for(i=1 ; i<=10 ; i++){		//Add to the set every Id from 1 to 10
		set_add(set, i);
	}

	printf("Tis is the image of the set before any deletes\n");
	set_print(set);

	for(i=1 ; i<=10 ; i++){
		if(i%2 == 0) {
			set_del(set, i);
			printf("This is the image of the set after deleting Id %d\n",i);
			set_print(set);
		}
	}

	set_print(set);

	for(i=1 ; i<=10 ; i++){
		if(set_search_id(set,i) == NO_ID){
			printf("The id %d does not exist in the set\n", i);
		} else {
			printf("The id %d exists in the set\n", i);
		}
	}

	set_destroy(set);

	printf("This is the end of the set_test\n");
	return(0);
}