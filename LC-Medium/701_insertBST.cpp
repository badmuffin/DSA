/*
701. Insert into a Binary Search Tree - Medium
----------------------------------------------
You are given the root node of a binary search tree (BST) and a value to
insert into the tree. Return the root node of the BST after the insertion.
It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as
long as the tree remains a BST after insertion. You can return any of them.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive solution
// T.C. -> O(h) in Best case(balanced tree), O(n) in worst case(skewed tree)
// S.C. -> same as T.C.
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        TreeNode *temp = new TreeNode(val);
        return temp;
    }

    else if (val > root->val)
        root->right = insertIntoBST(root->right, val);
    else
        root->left = insertIntoBST(root->left, val);

    return root;
}


// iterative solution - same T.C but Constant S.C.
TreeNode *insertIntoBSTiterative(TreeNode *root, int val)
{
    // create a temp node
    TreeNode *temp = new TreeNode(val);

    // base case
    if (root == nullptr)
        return temp;

    TreeNode *curr = root;

    while (true)
    { // infinite loop, because we're guranteed
        if (val > curr->val)
        {
            if (curr->right == nullptr)
            {
                curr->right = temp;
                return root;
            }
            else
                curr = curr->right; // handled in next iteration
        }
        else
        {
            if (curr->left == nullptr)
            {
                curr->left = temp;
                return root;
            }
            else
                curr = curr->left; // handled in next iteration
        }
    }

    return root;
}