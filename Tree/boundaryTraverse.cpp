#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode *buildTree(TreeNode *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    // create a root node
    root = new TreeNode(data);

    // condition for empty node
    if (data == -1)
        return nullptr;

    // recursive calls for child nodes
    cout << "Enter the value for inserting left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the value for inserting right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void traverseLeft(TreeNode *root, vector<int> &ans)
{
    // base case
    // root not exist
    if (root == nullptr)
        return;
    // leaf node
    if (root->left == nullptr and root->right == nullptr)
        return;

    // not a leaf node
    ans.push_back(root->data);

    (root->left)
        ? traverseLeft(root->left, ans)
        : traverseLeft(root->right, ans);
}

void traverseLeaf(TreeNode* root, vector<int> &ans) {
    // base case
    if(root == nullptr) return;
    
    // leaf node
    if(root->left == nullptr and root->right == nullptr) {
        ans.push_back(root->data);
        return;
    }
    // not a leaf node
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode *root, vector<int> &ans)
{
    // base case
    // root not exist
    if (root == nullptr)
        return;
    // leaf node
    if (root->left == nullptr and root->right == nullptr)
        return;
    
    // not a leaf node
    (root->right)
        ? traverseRight(root->right, ans)
        : traverseRight(root->left, ans);
    
    // insert only after coming back from recursive call
    // to have reverse order
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(TreeNode* root) {
    // create a ans vector
    vector<int> ans;
    if(root == nullptr) ans;

    //insert root value before recursive calls
    ans.push_back(root->data);

    // traverse left boundary of the tree
    traverseLeft(root->left, ans);

    // traverse leaf nodes of left and right subtree
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // traverse rigt boundary of the tree
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    TreeNode *root = nullptr;

    root = buildTree(root);

    vector<int> ans = boundaryTraversal(root);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

// Input string - 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
/*
            1
        2       3
    4      5
         6   7
*/

// output - 1 2 4 6 7 3