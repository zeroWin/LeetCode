/**
 * 19. Remove Nth Node From End of List
 * Given a linked list, remove the nth node from the end of list and return its head.

 * For example,

 * Given linked list: 1->2->3->4->5, and n = 2.

 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 // 还有更加卓越的方法。
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // 题目说n始终有效，就是说不必判断n比链表长度长的情况
	struct ListNode *srNode = head;
	int listLen = 0;
	
	// 统计链表长度
	while(srNode != NULL)
	{
		++listLen;
		srNode = srNode->next;
	}
	if(listLen <= 1)
		return NULL;
	

	int delNode = listLen - n + 1; // 删除的节点是第几个
	srNode = head;
	if(delNode == 1) // 头节点删除
		head = head->next;
	else
	{
		int i = 2;
		while(i != delNode) //sr指向要删除节点的上一个节点
		{
			++i;
			srNode = srNode->next;
		}
		srNode->next = srNode->next->next;
	}
	return head;
}




