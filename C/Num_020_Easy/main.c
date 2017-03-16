/**
 * 20. Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
bool isValid(char* s) {
    int sLen = strlen(s);
	if(sLen  == 0 || sLen  % 2 == 1)
		return false;
	
	int buffLen = sLen / 2;
	int *buff = (int *)malloc(sizeof(int)*(buffLen));
	
	int i = 0;
	
	while(*s != '\0')
	{
		if(*s == '(' || *s == '{' || *s == '[')//入栈
		{
			if(i >= buffLen) //
				return false;
			buff[i] = *s; // 入栈
			++i;
			++s;
		}
		else
		{
			--i;
			if(i < 0)
				return false;
			if(*s == ')' && buff[i] != '(')
				return false;
			if(*s == '}' && buff[i] != '{')
				return false;
			if(*s == ']' && buff[i] != '[')
				return false;
			++s;
		}
	}
	
	// 堆栈还有元素，返回错误
	if(i != 0)
	    return false;
	return true;
}


























