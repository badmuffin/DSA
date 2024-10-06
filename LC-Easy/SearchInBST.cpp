/*
700. Search in a Binary Search Tree - Easy
------------------------------------------
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the
subtree rooted with that node. If such a node does not exist, return null.
*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// iterative solution TC - O(H) SC - O(1)
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != nullptr)
    {
        if (root->val == val)
            return root;

        if (root->val < val)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}

// recursive solution TC - O(h)  SC - O(h)
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return root;

    if (root->val == val)
        return root;
    else if (root->val < val)
        return searchBST(root->right, val);
    else
        return searchBST(root->left, val);
}