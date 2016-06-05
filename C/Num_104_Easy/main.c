/**
 * 104. Maximum Depth of Binary Tree
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 **/

#include <stdio.h>
#include <stdlib.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
int maxDepth(struct TreeNode* root);

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
int maxDepth(struct TreeNode* root) {
    int leftDepth = 0;
    int rightDepth = 0;
    if(root == NULL)
        return 0;
    leftDepth = maxDepth(root->left) + 1;
    rightDepth = maxDepth(root->right) + 1;
    return leftDepth > rightDepth ? leftDepth:rightDepth;
}
