/**
 * 3. Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.

 * Examples:

 * Given "abcabcbb", the answer is "abc", which the length is 3.

 * Given "bbbbb", the answer is "b", with the length of 1.

 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
 
 int lengthOfLongestSubstring(char* s) {
    // 不考虑s为NULL的情况
	int longestSub = 0;
	int longestSubTemp = 0;
	int startLocal = 0;
	int endLocal = 0;
	int i;
	while(s[endLocal] != '\0')
	{
		for(i = startLocal; i < endLocal; ++i)
		{
			if(s[i] == s[endLocal]) // 找到和最新一个重复的
			{
				startLocal = i + 1;
				break;
			}
		}
		
		longestSubTemp = endLocal - startLocal + 1;
		if(longestSubTemp > longestSub)
			longestSub = longestSubTemp;
		++endLocal;
	}	
	return longestSub;
}
































