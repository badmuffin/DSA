#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
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

TreeNode* buildTree(TreeNode* root) {
    cout << "Enter the data: ";
    int data;
    cin >> data;

    // create a root node (passed root is null)
    root = new TreeNode(data);

    // condition for null node
    if(data == -1) return nullptr;

    // recursive call for childnodes
    cout << "Enter the value for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the value for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inorder(TreeNode* root, vector<int> &ans) {
    if(root == nullptr) return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void preorder(TreeNode* root) {
    if(root== nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = nullptr;
    root = buildTree(root);

    // inorder
    vector<int> inorderResult;
    inorder(root, inorderResult);
    cout << "Inorder traversal:- ";
    for(int i=0; i<inorderResult.size(); i++)
        cout << inorderResult[i] << " ";
    cout << endl;

    // preorder
    cout << "Preorder traversal:- ";
    preorder(root);
    cout << endl;

    // postorder
    cout << "Postorder traversal:- ";
    postorder(root);
    cout << endl;

    return 0;
}

/*
Input String :- 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
        1
    2       5
  3   4   6   7

Output:-
    Inorder - 3 2 4 1 6 5 7 (left - data - right)
    Preorder - 1 2 3 4 5 6 7 (data - left - right)
    Postorder - 3 4 2 6 7 5 1 (left - right - data)
*/
