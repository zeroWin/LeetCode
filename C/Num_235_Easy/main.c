/**
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).��
 *
 *         _______6______
 *        /              \
 *     ___2__          ___8__
 *    /      \        /      \
 *    0      _4       7       9
 *          /  \
 *          3   5
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 **/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);

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
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int rootValue;
    int pValue = p->val;
    int qValue = q->val;
    if(root == NULL)
        return NULL;
    if(p == NULL && q == NULL)
    {
        while(root->left != NULL)
            root = root->left;
        return root;
    }
    if(p == NULL) return q;
    if(q == NULL) return p;
    while(1)
    {
        rootValue = root->val;
        // ��������ж����������ں�
        if(pValue < rootValue && qValue < rootValue)
        {
            if(root->left == NULL)
                return root;
            root = root->left;
        }
        else if(pValue > rootValue && qValue > rootValue)
        {
            if(root->right == NULL)
                return root;
            root = root->right;
        }
        else // ������������Ҫ�Ǹ�if������ֱ����else������Щ����
            //if((pValue < rootValue && qValue > rootValue) || ((pValue > rootValue && qValue < rootValue))|| pValue == rootValue || qValue == rootValue)
            return root;
    }
}

//        while ((rootValue - pValue) * (rootValue - qValue) > 0) // ����ͬʱС�ڻ�ͬʱ���ڲų���
//            root = pValue < rootValue  ? root->left : root->right;// ����ط�����Ҫ�ж��½ڵ��Ƿ���ڵģ��������Ӻ��Һ��Ӷ���ָ���Լ�
//        return root;
