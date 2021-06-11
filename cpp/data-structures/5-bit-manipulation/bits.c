#include "bits.h"
#include <stdio.h>

/* Helper Functions */
int getBit(int num, int i){
    return (num & (1 << i)) != 0;
}

int setBit(int num, int i){
    return num | (1 << i);
}

int clearBit(int num, int i){
    int mask = ~(1 << i);
    return num & mask;
}

void decToBin(int n){
    // Size of the integer is assumed to be 32 bits.
    for(int i = 31; i >= 0; i--){
        int k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    return;
}
int main(){

    return 0;
}