/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 15, 2013
 Problem:    MorrisPostorderTraversal
 Notes:      Implement binary tree postorder traversal using Morris Method.
 Solution:   See my blog.(in chinese)
 */
#include "stdio.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
{
    if (from == to)
        return;
    TreeNode *x = from, *y = from->right, *z;
    while (true)
    {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
        if (x == to)
            break;
    }
}

void printReverse(TreeNode* from, TreeNode *to) // print the reversed tree nodes 'from' -> 'to'.
{
    reverse(from, to);

    TreeNode *p = to;
    while (true)
    {
        printf("%d ", p->val);
        if (p == from)
            break;
        p = p->right;
    }

    reverse(to, from);
}

void postorderMorrisTraversal(TreeNode *root) {
    TreeNode dump(1);
    dump.left = root;
    TreeNode *cur = &dump, *prev = NULL;
    while (cur)
    {
        if (cur->left == NULL)
        {
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                printReverse(cur->left, prev);  // call print
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(9);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(6);
    /*
          9
        /   \
       5     8
      / \     \
     1   4     7
        / \   /
       2   3 6
    */

    postorderMorrisTraversal(root);
    printf("\n");
    postorderMorrisTraversal(root); // check to see if the tree structure remains the same

    return 0;
}
