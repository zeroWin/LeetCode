/**
 * 226. Invert Binary Tree
 * Invert a binary tree.
         4
       /   \
      2     7
     / \   / \
    1   3 6   9
 * to
         4
       /   \
      7     2
     / \   / \
    9   6 3   1
 **/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
struct TreeNode* invertTree(struct TreeNode* root);
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
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *Temp;
    if(root == NULL)
        return NULL;
    Temp = root->left;
    root->left = root->right;
    root->right = Temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
