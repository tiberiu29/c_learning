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

   printf("SIZE IS: %d\n", array_list->size);
   printf("get element %d at index: %d\n", 
           get(array_list, 9), 9);
   

   //test underflow size_t not occuring
   add(array_list, 0, 999);
   printf("Element added at index %d with shift: %d\n", 
           0, array_list->data[0]);
   printf("Array size increased post shift, found element %d at index %d\n", 
           get(array_list, 10), 10);
   
   destroy(array_list);

}
