/**
 * 13. Roman to Integer
 * Given a roman numeral, convert it to an integer.

 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s);

int main()
{
    printf("Hello world!\n");
    return 0;
}


int romanToInt(char* s) {
    int num = 0;
    int sLen = 0;
    int i;
    if(s != NULL)
    {
        sLen = strlen(s);
        for(i = 0; i < sLen; ++i)
        {
            switch(s[i])
            {
            case 'I':
                if((i + 1) < sLen && s[i+1]=='V')
                {
                    num += 4;
                    i++;
                }
                else if((i + 1) < sLen && s[i+1]=='X')
                {
                    num += 9;
                    i++;
                }
                else
                    num += 1;
                break;
            case 'V':num += 5; break;
            case 'X':
                if((i + 1) < sLen && s[i+1]=='L')
                {
                    num += 40;
                    i++;
                }
                else if((i + 1) < sLen && s[i+1]=='C')
                {
                    num += 90;
                    i++;
                }
                else
                    num += 10;
                break;
            case 'L':num += 50; break;
            case 'C':
                if((i + 1) < sLen && s[i+1]=='D')
                {
                    num += 400;
                    i++;
                }
                else if((i + 1) < sLen && s[i+1]=='M')
                {
                    num += 900;
                    i++;
                }
                else
                    num += 100;
                break;
            case 'D':num += 500; break;
            case 'M':num += 1000; break;
            default:break;
            }
        }
    }
    return num;
}
