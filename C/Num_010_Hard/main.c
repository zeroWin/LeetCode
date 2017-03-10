/**
 * 10. Regular Expression Matching
 * Implement regular expression matching with support for '.' and '*'.

 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.

 * The matching should cover the entire input string (not partial).

 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)

 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 *
 */


bool isMatch(char* s, char* p) {
	if(s == NULL || p == NULL)
		return false;
	
    int sLen = strlen(s);
	int pLen = strlen(p);
	int sTemp = 0;
	int pTemp = 0;
	bool result = false;
	
	for(pTemp = 0;pTemp < pLen; ++pTemp)
	{
		int index = pTemp;
		for(sTemp = 0;sTemp < sLen; ++sTemp)
		{
			if(p[index] == '.')
			{
				
			}
		}
	}
	
	return result;
}



















