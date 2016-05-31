#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* reverseString(char* s);
int main()
{
    char s[] = "abcdefg";
    char *result = reverseString(s);
    printf("%s",result);
    return 0;
}

//char* reverseString(char* s) {
// int l = 0;
// int r = strlen(s)-1;
// char c;
//
// while(l<r)
// {
//     // swap chars
//     c = s[l];
//     s[l] = s[r];
//     s[r] = c;
//     l++;
//     r--;
// }
//
// return s;
//}


char* reverseString(char* s) {
    int strLength = strlen(s);
    char charTemp;
    int i = 0;
    while(i < strLength/2)
    {
        charTemp = s[strLength - i - 1];
        s[strLength - i - 1] = s[i];
        s[i] = charTemp;
        i++;
    }
    return s;
}
