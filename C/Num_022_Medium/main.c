/**
 * 22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 * For example, given n = 3, a solution set is:

 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 **/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char **result = NULL;
	*returnSize = 0;
	if(n <= 0)
		return result;
	
	
	int *soulNum = (int *)malloc(sizeof(int)*(n + 1));
	int i;
	soulNum[0] = 1;
	soulNum[1] = 1;
	
	for(i = 2; i <= n; ++i)
	{
		int j;
		int num = 0;
		for(j = 0; j < i; ++j)
			num += soulNum[j] * soluNum[i-j-1];

		soulNum[i] = num;
	}
	
	// 第n即为个数
	*returnSize = soulNum[n];
	
	// 开辟存储空间
	result = (char **)malloc(sizeof(char *)*soulNum[n]);
	for(i = 0; i < soulNum[n]; ++i)
		result[i] = (char *)malloc(sizeof(char)*(2*n+1));


	return result;
}
























