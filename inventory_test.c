#include <stdio.h>
#include "inventory.h"


int main(void) {
  printf("This is the start of the inventory test\n");
  Inventory* inv = inventory_create();
  int max = 20;

  inventory_set_max_objects(inv, max);
  for (Id id = 1; id <= 10; id++) {
    inventory_add_object(inv, id);
  }

  inventory_print(inv);

  printf("Now the odd-number objects will be deleted from the inventory\n\n");

  for (Id id = 1; id < 10; id+=2) {
    inventory_del_object(inv, id);
  }

  inventory_print(inv);

  printf("This is the end of the inventory test\n");

}
