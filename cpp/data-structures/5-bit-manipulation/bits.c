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

/* Bit Insertion 
    Given two, 32-bit numbers N & M, and 2 bit positions i & j, write a method to insert
    M into N such that M starts at position j and ends at bit i. You can assume
    that the bits j through i have enough space to fit all of M. That is, 
    if M = 10011, you can assume that there are ay least 5 bits between j and i. 
    You would not, for example, have j = 3, and i = 2, since M wouldn't fit.
*/
int bitInsertion(int N, int M, int i, int j){
    int x = 0;
    int new_N = N;
    for(int k = 0; k < 32; k++){
        if(k <= i && k >= j){
            new_N = getBit(M, x) ? setBit(new_N, k) : clearBit(new_N, k);
            x++;
        } else{
            new_N = getBit(N, k) ? setBit(new_N, k) : clearBit(new_N, k);
        }
    }
    printf("Original N Value: ");
    decToBin(N);

    printf("Value of M: ");
    decToBin(M);
        
    printf("New N Value: ");
    decToBin(new_N);
    return N;
}



int main(){

    return 0;
}