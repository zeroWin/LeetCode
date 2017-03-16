/**
 * 21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 **/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *nowNode = NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->val < l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    nowNode = head;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            nowNode->next = l1;
            nowNode = l1;
            l1 = l1->next;
        }
        else
        {
            nowNode->next = l2;
            nowNode = l2;
            l2 = l2->next;
        }
    }
    while(l1 != NULL)
    {
        nowNode->next = l1;
        nowNode = l1;
        l1 = l1->next;
    }

    while(l2 != NULL)
    {
        nowNode->next = l2;
        nowNode = l2;
        l2 = l2->next;
    }
    return head;
}
