/**
 * 83. Remove Duplicates from Sorted List
 * Given a sorted linked list, delete all duplicates such that each element appear only once.

 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 **/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head);
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
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* srcNode = head;
    while(srcNode != NULL && srcNode->next != NULL)
    {
        if(srcNode->val == srcNode->next->val)
            srcNode->next = srcNode->next->next;
        else
            srcNode = srcNode->next;
    }
    return head;
}
