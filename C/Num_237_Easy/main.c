/**
 * 237. Delete Node in a Linked List
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 * Evaluate:no diffcult
 * 题意理解的有问题，没搞清楚给的到底是什么，给的是要删除的节点，而不是链表
 **/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
void deleteNode(struct ListNode* node);
int main()
{
    struct ListNode listNode[3];
    listNode[0].val = 0;
    listNode[0].next = &listNode[1];
    listNode[1].val = 1;
    listNode[1].next = &listNode[2];
    listNode[2].val = 0;
    listNode[2].next = NULL;
    deleteNode(listNode);
    return 0;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if(node == NULL) return;
    if(node->next != NULL)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
}
