#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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

TreeNode* buildTree(TreeNode* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    // root is null, so data will be our root
    root = new TreeNode(data);

    // condition for empty or null node
    if(data == -1) return nullptr;

    // recursive calls for child nodes
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
};

vector<int> zigzagTraversal(TreeNode* root) {
    // create a result vector
    vector<int> result;

    // base case
    if(root == nullptr) return result;

    queue<TreeNode *> q; // create a que, used in level order
    q.push(root);

    // flag var (true - normal order, fase - reverse order)
    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        // create a temporary varible to store the level's data
        vector<int> temp(size);

        // processing for the level
        for(int i=0; i<size; i++) {
            TreeNode* frontData = q.front();
            q.pop();

            // i - normal order "size-i-1" - reverse order
            int index = leftToRight ? i : size-1-i;
            temp[index] = frontData->data;

            if(frontData->left)
                q.push(frontData->left);
            if(frontData->right)
                q.push(frontData->right);
        }

        // change the direction
        leftToRight = !leftToRight;

        // copy level's data into the result;
        for(auto i: temp)
            result.push_back(i);
    }
    return result;
}

void inorder(TreeNode* root) {

}

int main() {
    TreeNode* root = nullptr;
    root = buildTree(root);

    vector<int> res;
    res = zigzagTraversal(root);
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}

/*
input string - 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 -1
Tree :-
        1
    2       5
 3     4  6

output - 1 5 2 3 4 6
*/
