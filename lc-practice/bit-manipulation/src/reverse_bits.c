#include "reverse_bits.h"
#include "stdint.h"

int single_bit_mask(int position) {
    return 1u << position;
}

int reverseBits(int n) {
    
    int start = 0;
    int end = sizeof(n) * 8 - 1; 
    int current_mask = 0u;

    while(start < end) {
        int mask_start = single_bit_mask(start);
        int mask_end = single_bit_mask(end);

        int value_start = (n & mask_start) >> start;
        int value_end = (n & mask_end) >> end;

        if(value_start != value_end) {
           current_mask = current_mask | mask_start | mask_end; 
        }
        start++;
        end--;
    }

    return n ^ current_mask;
}
