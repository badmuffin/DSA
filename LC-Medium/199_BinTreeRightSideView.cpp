/*
199. Binary Tree Right Side View - Medium
------------------------------------------
Given the root of a binary tree, imagine yourself standing on the right side
of it, return the values of the nodes you can see ordered from top to bottom.
*/

#include <vector>
#include <queue>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    queue<TreeNode *> que;

    if (root == nullptr)
        return result;
    que.push(root);

    while (!que.empty()) {
        // size of the que at current level
        int size = que.size();

        for (int i = 0; i < size; i++) {
            // first element
            TreeNode *temp = que.front();
            que.pop();

            // if last iteration -> rightmost node
            if (i == size - 1)
                result.push_back(temp->val);

            // pushing child of the each node in the curr level
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
    }
    return result;
}