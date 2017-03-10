/**
 * 14. Longest Common Prefix
 Write a function to find the longest common prefix string amongst an array of strings.
 *
 */

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)
		return "";
	if(strsSize == 1)
		return strs[0];
	
	int strCommon = strlen(strs[0]);
	int i;
	for(i = 1; i < strsSize; ++i)
	{
		int j;
		int end;
		int strNext = strlen(strs[i]); // 要比较的数组长度
		if(strNext > strCommon)
			end = strCommon;
		else
			end = strNext;
		for(j = 0; j < end; ++j)
		{
			if(strs[i][j] == strs[i-1][j])
				continue;
			else
				break;
		}
		
		if(j < strCommon)
			strCommon = j;//相同的个数
	}
	
	char *result = (char *)malloc(sizeof(char)*(strCommon+1));
	for(i = 0;i < strCommon; ++i)
		result[i] = strs[0][i];
	
	result[strCommon] = '\0';
	return result;
	
}