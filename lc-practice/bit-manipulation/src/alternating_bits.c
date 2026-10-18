#include "alternating_bits.h"
#include <stddef.h>

size_t last_on_bit_index(int n) {
    size_t last_on_bit_index = 0;
    while(n != 0){
        n = n >> 1;
        last_on_bit_index++;
    }
    return last_on_bit_index;
}

bool hasAlternatingBits(int n){
  size_t slow_p = 0;
  size_t fast_p = 1;

  size_t end = last_on_bit_index(n);

  while(fast_p < end) {
      int bit = (n >> slow_p) & 1;
      int neighbor_bit = (n >> fast_p) & 1;
      if(bit == neighbor_bit) {
          return false;
      }
      slow_p ++;
      fast_p ++;
  }

  return true;
}
