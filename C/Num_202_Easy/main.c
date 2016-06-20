/**
 * 202. Happy Number
 * Write an algorithm to determine if a number is "happy".

 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

 * Example: 19 is a happy number

 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isHappy(int n);

int main()
{
    isHappy(99);
    return 0;
}

//bool isHappy(int n) {
//    int sum = 0;
//    int num = 0;
//    int numHava = 0;
//    int *haveExist = (int *)malloc(sizeof(int) * 10000);
//    int i;
//    haveExist[numHava++] = n;
//    if(n <= 0)
//        return false;
//    while(n != 1)
//    {
//        while((num = n % 10) != 0 || n / 10 != 0)
//        {
//            sum += num*num;
//            n = n / 10;
//        }
//        n = sum;
//        printf("%d\n",n);
//        sum = 0;
//        numHava++;
//        i = numHava - 2;
//        while(i >= 0 && haveExist[i] > n)
//        {
//            haveExist[i + 1] = haveExist[i];
//            i = i - 1;
//        }
//        if(i >= 0 && haveExist[i] == n)
//        {
//            free(haveExist);
//            return false;
//        }
//        haveExist[i+1] = n;
//   }
//   free(haveExist);
//   return true;
//}

int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}
