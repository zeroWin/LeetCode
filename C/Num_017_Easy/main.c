/**
 * 17. Letter Combinations of a Phone Number
 * Given a digit string, return all possible letter combinations that the number could represent.

 * A mapping of digit to letters (just like on the telephone buttons) is given below.



 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
	char **result = NULL;
	int numLen = strlen(digits);
	*returnSize = 0;
	// 纵轴代表数字几，横轴代表内容
	char dir[10][5] =
	{
		{ 0 }, //0
		{ 0 }, //1
		{ 3,'a','b','c' },	//2
		{ 3,'d','e','f' },	//3
		{ 3,'g','h','i' },	//4
		{ 3,'j','k','l' },	//5
		{ 3,'m','n','o' },	//6
		{ 4,'p','q','r','s' },	//7
		{ 3,'t','u','v' },	//8
		{ 4,'w','x','y','z' },	//9
	};

	int i;
	int strNum = 1;  // 字符串个数
	int strLong = 0; // 每个字符串长度
	for (i = 0; i < numLen; ++i)
	{
		if (digits[i] == '0' || digits[i] == '1') //如果数字是1或者0，就出错返回
	    {
	        strNum = 1;
	        break;
	    }
		strNum = strNum * dir[digits[i] - '0'][0];
		++strLong;
	}
    if(strNum == 1)
    {
        return result;
    }
	*returnSize = strNum;
    
	//开辟空间
	result = (char **)malloc(sizeof(char *)*strNum);
	for (i = 0;i < strNum; ++i)
		result[i] = (char *)malloc(sizeof(char) * (strLong + 1));

	int div = strNum;
	int row = 0;
	for (i = 0;i < numLen; ++i)
	{
		div = div / dir[digits[i] - '0'][0]; //每个字母重复的次数
		int j;
		for (j = 0; j < strNum; ++j)
			result[j][row] = dir[digits[i] - '0'][(j / div) % (dir[digits[i]-'0'][0]) + 1]; // 这句话是关键

		++row;
	}

	for (i = 0;i < strNum; ++i)
		result[i][strLong] = '\0';


	return result;
}