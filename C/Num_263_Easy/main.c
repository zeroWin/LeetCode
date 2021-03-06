/**
 * 263. Ugly Number
 * Write a program to check whether a given number is an ugly number.

 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

 * Note that 1 is typically treated as an ugly number.
 *
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isUgly(int num);
int main()
{
    printf("Hello world!\n");
    return 0;
}

bool isUgly(int num) {
    while(num > 1)
    {
        if(num % 2 == 0)
            num /= 2;
        else if(num % 3 == 0)
            num /= 3;
        else if(num % 5 == 0)
            num /= 5;
        else
            return false;
    }
    if(num == 1)
        return true;
    else
        return false;
}
