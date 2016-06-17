/**
 * 326. Power of Three
 * iven an integer, write a function to determine if it is a power of three.

 * Follow up:
 * Could you do it without using any loop / recursion?
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfThree(int n);
int main()
{
    printf("Hello world!\n");
    return 0;
}

bool isPowerOfThree(int n) {
    while( n > 1 && (n % 3) == 0)
        n = n / 3;
    if(n == 1)
        return true;
    else
        return false;

}

//// 有更快的方法，仔细思考，下次想出来
