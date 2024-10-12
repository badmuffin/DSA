/*
1448. Count Good Nodes in Binary Tree - Medium
----------------------------------------------
Given a binary tree root, a node X in the tree is named good if in the
path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

 */

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
  public:
    int goodNodes(TreeNode *root)
    {
        return helper(root, root->val);
    }

  private:
    int helper(TreeNode *root, int maxSoFar)
    {
        if (root == nullptr)
            return 0;

        // if condition satisfied then root node is good node, so increase the count
        int result = root->val >= maxSoFar ? 1 : 0;

        // update the maxSoFar
        maxSoFar = max(maxSoFar, root->val);

        // add the result of left and right subtree to the result
        result += helper(root->left, maxSoFar);
        result += helper(root->right, maxSoFar);

        return result;
    }
};
