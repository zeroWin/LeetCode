/**
 * 2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single
 * digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8

 * Subscribe to see which companies asked this question.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	// 依旧不考虑输入为NULL的情况
	struct ListNode* search_l1 = l1;
	struct ListNode* search_l2 = l2;
	struct ListNode *result = NULL;
	int carry = 0;
	int sum = 0;
	int flag = 0;
	
	while(search_l1 != NULL | search_l2 != NULL)
	{
		if(search_l1 != NULL)
		{
			sum = sum + search_l1->val;
			search_l1 = search_l1->next;
		}
		if(search_l2 != NULL)
		{
			sum = sum + search_l2->val;
			search_l2 = search_l2->next;
		}
		
		sum += carry;
		carry = sum / 10;
		if(flag == 0) // 第一次
		{
			struct ListNode *search_result =(struct ListNode *)malloc(sizeof(struct ListNode));
			search_result->val = sum % 10;
			search_result->next = NULL;
			result = search_result;
			flag = 1;
		}
		else
		{
			search_result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			search_result = search_result->next;
			search_result->val = sum % 10;
			search_result->next = NULL;
		}
		sum = 0;
	}	
	if(carry != 0) // 有进位
	{
		search_result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		search_result = search_result->next;
		search_result->val = carry;
		search_result->next = NULL;		
	}
	
	
	return result;
	
}










/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // 1. 一开始没有注意到可能是两个字符串数字，用int求和这种方法可能超了上限。
 // 2. 没有注意到结束的时候可能有进位的情况。
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int num_carry = 0;
    int num_sum = 0;
    struct ListNode* returnListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* findListNode = returnListNode;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
        
    while(l1 != NULL || l2 != NULL)
    {
        if(l1 != NULL)
        {
            num_sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            num_sum += l2->val;
            l2 = l2->next;
        }
        num_sum += num_carry; // 加上进位
        
        num_carry = num_sum / 10; // 进位
        num_sum = num_sum % 10; // 个位数
        findListNode->val = num_sum;
        
        num_sum = 0;
        if(l1 != NULL || l2 != NULL)
        {
            findListNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            findListNode = findListNode->next;
        }
        else
        {
           if(num_carry == 0)
           {
               findListNode->next = NULL;
           }
           else
           {
               findListNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
               findListNode = findListNode->next; 
               findListNode->val = num_carry;
               findListNode->next = NULL;
           }
            
        }
    }
    return returnListNode;
    
    
}







