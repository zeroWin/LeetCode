/**
 * 24. Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.

 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.

 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 **/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head);

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
 // µÝ¹é
//struct ListNode* swapPairs(struct ListNode* head) {
//    struct ListNode *headNext = NULL;
//    if(head == NULL)
//        return NULL;
//    if((headNext = head->next) == NULL)
//        return head;
//
//    head->next = headNext->next;
//    headNext->next = head;
//    head = headNext;
//
//    head->next->next = swapPairs(head->next->next);
//    return head;
//}

// ·ÇµÝ¹é
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *headNext = NULL;
    struct ListNode *srcNode = head;
    struct ListNode *preNode = NULL;
    int i = 0;
    while(srcNode != NULL && (headNext = srcNode->next) != NULL)
    {
        srcNode->next = headNext->next;
        headNext->next = srcNode;
        if(i == 0)
        {
            head = headNext;
            i++;
        }
        else
            preNode->next = headNext;
        preNode = srcNode;
        srcNode = srcNode->next;
    }

    return head;
}
