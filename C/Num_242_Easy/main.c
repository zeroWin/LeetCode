/**
 * 242. Valid Anagram
 * Given two strings s and t, write a function to determine if t is an anagram of s.

 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.

 * Note:
 * You may assume the string contains only lowercase alphabets.

 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t);
int main()
{
    printf("Hello world!\n");
    return 0;
}


bool isAnagram(char* s, char* t) {
    int buffer[26] = {0};
    int sLength = strlen(s);
    int tLength = strlen(t);
    int i;
    for(i = 0;i < sLength;++i )
        buffer[s[i]-'a']++; // 减a这个没想到不应该，还去查ascii去减97，完全没必要，思维还是不够灵活
    for(i = 0;i < tLength;++i )
        buffer[t[i]-'a']--;
    for(i = 0;i < 26; ++i )
        if(buffer[i] != 0)
            return false;
    return true;
}
