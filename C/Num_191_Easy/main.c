/**
 * 191. Number of 1 Bits
 * Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).

 * For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int hammingWeight(uint32_t n);
int main()
{
    printf("Hello world!\n");
    uint32_t a = 0xFFFFFFFF;
    printf("%x",a);
    return 0;
}

int hammingWeight(uint32_t n) {
    int bit1Num = 0;
    while(n != 0)
    {
        if((n & 0x1) == 1)
            bit1Num++;
        n = n >> 1;
    }
    return bit1Num;
}
