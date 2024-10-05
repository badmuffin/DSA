/*
572. Subtree of Another Tree - Easy
-----------------------------------
Given the roots of two binary trees root and subRoot, return true if there is a subtree 
of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of 
this node's descendants. The tree tree could also be considered as a subtree of itself.

*/

class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool isSame(TreeNode* first, TreeNode* second) {
    // base cases
    if(first == nullptr and second == nullptr)
        return true;
    if(first == nullptr or second == nullptr)
        return false;

    return (
        isSame(first->left, second->left) and
        isSame(first->right, second->right) and
        first->data == second->data
    ) ? true : false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    // base case
    if(root == nullptr)
        return false;
    
    if(isSame(root, subRoot))
        return true;
    
    // recursive calls - check for childs of root
    return(
        isSubtree(root->left, subRoot) or
        isSubtree(root->right, subRoot)
    ) ? true : false;
}