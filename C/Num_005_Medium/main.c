/**
 * 5. Longest Palindromic Substring
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

 * Example:

 * Input: "babad"

 * Output: "bab"

 * Note: "aba" is also a valid answer.
 * Example:

 * Input: "cbbd"

 * Output: "bb"
 */
 
 // ������û�����ʲô�ǻ����ַ�������������βһ�����������Ŷ����Ŷ���һ��
 // Ȼ�����û�п��ǵ��м�������һ���������
 char* longestPalindrome(char* s) {
	 int local_left = 0;
	 int local_right = 0;
	 int i = 0,j;
	 int longest = 0;
	 int flag_ou = 0;
	 int flag_qi = 0;
	 if(s == NULL || s[0] == '\0' || s[1] == '\0' )
		 return s;
	 
	 while(s[i] != '\0')
	 {
		 for(j = 0; i-j>=0; ++j)
		 {
			 if(flag_ou == 0 && i-1 >= 0 && s[i] == s[i - 1]) // ż����,����һ��������
			 {
				 if(i-1-j >=0 && s[i-1-j] == s[i + j])
				 {
					 if(longest < 2*j + 2)
					 {
						 longest = 2*j + 2;
						 local_left = i - 1 - j;
						 local_right = i + j;
					 }
				 }
				 else
					 flag_ou = 1;
				 
			 }
			 else
				 flag_ou = 1;
			 
			 if(flag_qi == 0 && s[i - j] == s[i + j]) // �����
			 {
				 if(longest < (2*j + 1))
				 {
					 longest = 2*j + 1;
					 local_left = i - j;
					 local_right = i + j;
				 }
			 }
			 else
				 flag_qi = 1;
			 
			 if(flag_ou == 1 && flag_qi == 1)
				 break;
		 }
		 ++i;
		 flag_ou = 0;
		 flag_qi = 0;
	 }
	 char *result = (char *)malloc(sizeof(char)*(longest+1));
	 for(j = 0; j < longest; ++j)
		 result[j] = s[local_left + j];
	 result[longest] = '\0';
	 return result;
	 
	 
}