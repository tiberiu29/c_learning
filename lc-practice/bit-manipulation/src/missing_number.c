#include "missing_number.h"

/*
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.
*/
int missingNumber(int* nums, int numsSize) {
    int accumulator = 0;

    // XOR is associative + commutative
    // nums=[3, 0, 1] unsorted
    // expected [0, 1, 2, 3]
    // 3 ^ 0 ^ 0 ^ 1 ^ 1 ^ 2 ^ 3 <=> (3^3) ^ (0^0) & (1^1) ^ 2 = 0 ^ 2 = 2
    // remember a ^ a = 0 and a ^ 0 = a
    for(int i = 0; i < numsSize; i++){
        accumulator = accumulator ^ nums[i] ^ i;
    }

    return accumulator ^ numsSize;
}
