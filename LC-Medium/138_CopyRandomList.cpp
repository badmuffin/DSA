/*
138. Copy List with Random Pointer - Medium
--------------------------------------------

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

*/

#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // using two pass approach with hashmap
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMapper;
        // edge case, when random pointer is pointing to nullptr
        nodeMapper[nullptr] = nullptr;

        // first pass to copy nodes
        Node* curr = head;
        while (curr != nullptr) {
            Node* copy = new Node(curr->val);
            nodeMapper[curr] = copy;
            curr = curr->next;
        }

        // second pass to copy pointers
        curr = head;
        while (curr != nullptr) {
            Node* copy = nodeMapper[curr];
            copy->next = nodeMapper[curr->next];
            copy->random = nodeMapper[curr->random];
            curr = curr->next;
        }

        return nodeMapper[head];
    }
};