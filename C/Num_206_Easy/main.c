/**
 * 206. Reverse Linked List
 * Reverse a singly linked list.

 * click to show more hints.

 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 **/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head);
int main()
{
    printf("Hello world!\n");
    return 0;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *preNode = NULL;
    struct ListNode *nextNode = NULL;
    struct ListNode *nowNode = head;
    while(nowNode != NULL)
    {
        nextNode = nowNode->next;
        nowNode->next = preNode;
        preNode = nowNode;
        nowNode = nextNode;
    }
    return preNode;
}
