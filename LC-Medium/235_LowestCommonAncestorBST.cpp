/*
235. Lowest Common Ancestor of a Binary Search Tree - Medium
------------------------------------------------------------
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of 
two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is 
defined between two nodes p and q as the lowest node in T that has both p and q 
as descendants (where we allow a node to be a descendant of itself).”
*/

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr)
    {
        if( (root->val < p->val) and (root->val < q->val))
            root = root->right;
        else if( (root->val > p->val) and (root->val > q->val))
            root = root->left;
        // this consist of all the cases, which tells us that both
        // p and q are in different subtree
        // also include the edge case where one of the node is
        // the descendent of itself
        else
            return root;
    }

    return nullptr;    
}