/**
 * 171. Excel Sheet Column Number
 * Related to question Excel Sheet Column Title

 * Given a column title as appear in an Excel sheet, return its corresponding column number.

 * For example:

 *  A -> 1
 *  B -> 2
 *  C -> 3
 *  ...
 *  Z -> 26
 *  AA -> 27
 *  AB -> 28
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int titleToNumber(char* s);

int main()
{
    char *s = NULL;
    printf("%d,%d,%d",true,false,strlen(s));
    return 0;
}


int titleToNumber(char* s) {
    int strLen;
    int i;
    int column = 0;
    if(s == NULL)
        return 0;
    strLen = strlen(s);
    for(i = 0;i < strLen;++i)
        column = (s[i] - 'A' + 1) + column * 26;
    return column;
}
