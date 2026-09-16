#include "arraylist.h"
#include <stdio.h>

int main() {
   ArrayList *array_list = initialize(10);

   for(int i = 0; i < 100; i++) {
       push(array_list, i);
       printf("PUSHED: %d\n", get(array_list, i));
   }

   for(int i = 0; i < 90; i++) {
       int popped_value = pop(array_list);
       printf("POPPED%d\n", popped_value);
   }

   printf("SIZE IS: %zu\n", array_list->size);
   print_array(array_list);

   //test underflow size_t not occuring
   add(array_list, 0, 999);
   printf("SIZE IS: %zu\n", array_list->size);
   print_array(array_list);
   
   remove_at(array_list, 0);
   printf("SIZE IS: %zu\n", array_list->size);
   print_array(array_list);

   destroy(array_list);

}

