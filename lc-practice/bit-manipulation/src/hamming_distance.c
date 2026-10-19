#include "hamming_distance.h"

int hammingDistance(int x, int y){
    if(x == y) {
        return 0;
    }

    int end = sizeof(x) * 8;
    int counter = 0;

    while(x != 0 || y != 0){
        int x_bit = x & 1;
        int y_bit = y & 1;

        if(x_bit != y_bit) {
            counter ++;
        }
        x = x >> 1;
        y = y >> 1;
    }

    return counter;
}
