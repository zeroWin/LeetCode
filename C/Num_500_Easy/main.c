/**
 * 500. Keyboard Row
 * Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


 * American keyboard


 * Example 1:
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * Note:
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 **/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    char **result = NULL;
	int LetterLocal[26] = {2,1,1,2,3,2,2,2,3,2,2,2,1,1,3,3,3,3,2,3,3,1,3,1,3,1};
	int i;
	int flag = 0;
	*returnSize = 0;
	
	for(i = 0; i < wordsSize; ++i)
	{
		int strLen = strlen(words[i]); // 获取当前字符串长度		
		int temp;
		if(words[i][0] - 'a' < 0) // 是大写字母
			temp = words[i][0] - 'A';
		else
			temp = words[i][0] - 'a';
		
		temp = LetterLocal[temp];
		int j;
		for(j = 1; j < strLen; ++j)
		{
			if(words[i][j] - 'a' < 0 && LetterLocal[words[i][j]-'A'] != temp) // 是大写字母
				break;
			else if(words[i][j] - 'a' >= 0 && LetterLocal[words[i][j]-'a'] != temp)
				break;
		}
		if(j != strLen)
			continue;
		
		*returnSize += 1;
		if(flag == 1)
			result = (char **)malloc(sizeof(char *)*(*returnSize)); // 开辟空间
		else
			result = (char **)realloc(result,sizeof(char *)*(*returnSize));
		result[*returnSize - 1] = (char *)malloc(sizeof(char)*(strLen + 1));
		result[*returnSize - 1] = strcpy(result[*resultSize - 1],words[i]);
	}
	
	return result;
	
}
