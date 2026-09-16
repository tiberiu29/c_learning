#include "arraylist.h"
#include <stdio.h>

int main() {
   ArrayList *array_list = initialize(10);

   for(int i = 0; i < 100; i++) {
       push(array_list, i);
       printf("PUSHED: %d\n", get(array_list, i));
   }

   for(int i = 0; i < 50; i++) {
       int popped_value = pop(array_list);
       printf("POPPED%d\n", popped_value);
   }

   printf("SIZE IS: %d\n", array_list->size);
   printf("get element %d at index: %d\n", 
           get(array_list, 49), 49);
// printf("get out of bounds: %d\n", get(array_list, array_list->size));
   destroy(array_list);


}











