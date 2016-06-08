/**
 * 100. Same Tree
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 * Evalaute: no diffcult
 **/

#include <stdio.h>
#include <stdlib.h>

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q);
int main()
{
    printf("Hello world!\n");
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == q && p == NULL)
        return true;
    if(p == NULL || q == NULL || p->val != q->val)
        return false;
    if(isSameTree(p->left,q->left)) // ×óÊ÷ÏàÍ¬£¬ÅÐ¶ÏÓÒÊ÷
        return isSameTree(p->right,q->right);
    return false;
}
