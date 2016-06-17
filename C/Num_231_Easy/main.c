/**
 * 231. Power of Two
 * Given an integer, write a function to determine if it is a power of two.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPowerOfTwo(int n);
int main()
{
    printf("Hello world!\n");
    isPowerOfTwo(2);
    return 0;
}

//bool isPowerOfTwo(int n) {
//    while(n > 1 && (n % 2) == 0)
//        n = n / 2;
//    if(n == 1)
//        return true;
//    else
//        return false;
//}

//// 这种用最大的2的pow去对取mod的方法十分巧妙
//bool isPowerOfTwo(int n) {
//    int numMax = pow(2,(int)(log(0x7FFFFFFF)/log(2)));
//    if(n > 0 && (numMax % n) == 0)
//        return true;
//    else
//        return false;
//}

// 2的power只有一位为1，可以利用这个
bool isPowerOfTwo(int n) {
    int num = 0;
    int i;
    if(n <= 0) return false;
    for(i = 0;i < 32 && n != 0; ++i)
    {
        if(n & 0x1 == 1)
            num++;
        n = n >> 1;
    }
    if(num != 1)
        return false;
    return true;
}

// 借助2的pow只有一位为1，还有种更加快的方法，仔细思考
