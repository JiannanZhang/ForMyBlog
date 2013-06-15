/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 15, 2013
 Problem:    MorrisPreorderTraversal
 Notes:      Implement binary tree preorder traversal using Morris Method.
 Solution:   See my blog.(in chinese)
 */
#include "stdio.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)
            {
                printf("%d ", cur->val);  // the only difference with inorder-traversal
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    /*
          1
        /   \
       2     7   
      / \     \
     3   4     8
        / \   /
       5   6 9
    */

    preorderMorrisTraversal(root);
    printf("\n");
    preorderMorrisTraversal(root); // check to see if the tree structure remains the same

    return 0;
}
