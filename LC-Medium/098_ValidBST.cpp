/*
98. Validate Binary Search Tree - Medium
----------------------------------------
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
    -> The left subtree of a node contains only nodes with keys less than the node's key.
    -> The right subtree of a node contains only nodes with keys greater than the node's key.
    -> Both the left and right subtrees must also be binary search trees.

----------------------------------------

Points To remember :- 
    -> Every node at the left subtree should be smaller than the root node
    -> Every node at the right subtree should be greater than the root node

    tree
            5
        3       7
              4   8

    visualize with limits
                    5 (-infi < 5 < +infi)
        3 (-infi < 3 < 5)         7 (5 < 7 < infi)  
                            4 (5 < 4 < 7)       8 (7 < 8 < infi)            
*/

#include <climits>
#include <iostream>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool helper(TreeNode* root, long leftLimit, long rightLimit) {
    if(root == nullptr) return true;

    return (root->val > leftLimit and root->val < rightLimit) ?
        (helper(root->left, leftLimit, root->val) and helper(root->right, root->val, rightLimit)) :
        false;
}

bool isValidBST(TreeNode* root) {
    return(root, LONG_MIN, LONG_MAX);
}

