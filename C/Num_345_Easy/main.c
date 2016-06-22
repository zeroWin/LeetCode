/**
 * 345. Reverse Vowels of a String
 * Write a function that takes a string as input and reverse only the vowels of a string.

 * Example 1:
 * Given s = "hello", return "holle".

 * Example 2:
 * Given s = "leetcode", return "leotcede".

 * Subscribe to see which companies asked this question
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseVowels(char* s);

int main()
{
    printf("Hello world!\n");
    return 0;
}


char* reverseVowels(char* s) {
    int l = 0;
    int r = 0;
    char temp;
    if(s == NULL)
        return s;
    r = strlen(s) - 1;
    while(l < r)
    {
        if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u' || s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U')
        {
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u' || s[r] == 'A' || s[r] == 'E' || s[r] == 'I' || s[r] == 'O' || s[r] == 'U')
            {
                temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l++;
                r--;
            }
            else
                r--;
        }
        else
            l++;
    }
    return s;
}
