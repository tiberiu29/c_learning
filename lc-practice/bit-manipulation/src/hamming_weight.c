#include "hamming_weight.h"
#include <stddef.h>
#include <stdint.h>


/**
 * Given a positive integer n, write a function that returns the number of set bits in its binary representation 
 * (also known as the Hamming weight).
 */
int hammingWeight(int n) {
    size_t counter = 0;

    while(n != 0) {
        if((n & 1u) == 1) {
            counter++;
        }
        n = n >> 1;
    }

    return counter;

}
