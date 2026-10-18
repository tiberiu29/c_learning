#include "power_of_two.h"
#include <stddef.h>

/**
 *Given an integer n, return true if it is a power of two. Otherwise, return false.
 *An integer n is a power of two, if there exists an integer x such that n == 2x.
 */
bool isPowerOfTwo_hamming_weight_check(int n) {
    if(n == 0){
        return false;
    }
   
    size_t counter = 0;
    while(n != 0){
        if((n & 1) == 1) {
            if(counter == 1){
                return false;
            }
            counter ++;
        }

        n = n >> 1;
    }

    return true;
}

/**
 * Use the special property of subtracting 1 from an even number
 * EX: 0001 0000 - 1 = 0000 1111
 * 0001 0000
 * 0000 1111
 * --------- &
 * 0000 0000 
*/
bool isPowerOfTwo(int n) {
    if(n == 0) {
        return 0;
    }
    return (n & (n - 1)) == 0;
}
