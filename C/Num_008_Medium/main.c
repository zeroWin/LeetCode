/**
 * 8. String to Integer (atoi)
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 */

 // 主要是不知道什么情况下返回什么
 // 没必要写成循环判断，可以直接顺序判断，先判断是否为空格，然后判断正负号
 // 然后就循环判断数字即可。
 // 我的用循环写的方法就显得太麻烦了。
 // 判断是否越界的方法也很值得学习，用最大除10的方法判断上届，用最大除10 并且判断当前数是否大于7 的方法判断下界。
int myAtoi(char* str) {
    if(str == NULL)
		return 0;
	
	int i;
	long result = 0;
	int flag = 0;
	int num_fu = 1;
	for(i = 0; str[i] != '\0'; ++i )
	{
		if(!isdigit(str[i])) // 不是数字
		{
			if(flag == 0) // 开头遇到
			{
				if(str[i] == '-') // 下一个要是数字
				{
					flag = 1;
					num_fu = -1;
				}
				else if(str[i] == '+')
				{
					flag = 1;
					num_fu = 1;
				}
				else if(str[i] == ' ') // 空格跳过
					continue;
				else // 其他字符
					break;
			}
			else //在需要数字的地方再次遇到非数字
				break;
		}		
		else // 是数字
 		{
			flag = 1;
			result = 10 * result + (str[i] - '0');
			if(num_fu == 1 && result > (int)0x7FFFFFFF)
			{
				result = 0x7FFFFFFF;
				break;
			}
			if(num_fu == -1 && -result < (int)0x80000000)
			{
				result = -0x80000000;
				break;
			}
		}
	}
	
	return num_fu*result;
}
















