/*
230. Kth Smallest Element in a BST
*/
#include <stack>
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

int kthSmallest(TreeNode *root, int k)
{

    stack<TreeNode *> st;
    TreeNode *curr = root;
    int count = 1; // 1-indexed, track the count of node processing

    while (curr != nullptr or !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        // now curr is pointing to the nullptr
        curr = st.top();
        st.pop();

        // if count is equal to k, then return the curr popped value
        if (count == k)
            return curr->val;
        count++;

        curr = curr->right;
    }

    return -1;
}