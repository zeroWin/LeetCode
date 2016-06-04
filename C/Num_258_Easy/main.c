/**
 * 258. Add Digits
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 **/

#include <stdio.h>
#include <stdlib.h>

int addDigits(int num);
int main()
{
    printf("%d",addDigits(11));
    return 0;
}


int addDigits(int num) {
    int a = num % 9;
    if(num == 0) return 0;
    return a == 0 ? 9:a;
}
