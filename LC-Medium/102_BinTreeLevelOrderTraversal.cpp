/*
102. Binary Tree Level Order Traversal - Medium
-----------------------------------------------
Given the root of a binary tree, return the level order traversal of 
its nodes' values. (i.e., from left to right, level by level).

*/

#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    // Create a 2D vector to store the final result
    vector<vector<int>> result;

    // Base case: If the tree is empty, return an empty result
    if (root == nullptr)
        return result;

    // Create a queue for level order traversal
    queue<TreeNode *> que;
    // Push the root node into the queue
    que.push(root);

    // Continue until the queue is empty
    while (!que.empty())
    {
        int size = que.size();
        // Create a vector to store the values of nodes at the current level
        vector<int> ans;

        // Iterate through all nodes at the current level
        for (int i = 0; i < size; i++)
        {
            // get the front node
            TreeNode *temp = que.front();
            que.pop();

            // Add the value of the current node to the level vector
            ans.push_back(temp->val);

            // If the current node has childs, push it into the queue
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
        // add the level vector to the result
        result.push_back(ans);
    }
    return result;
}
