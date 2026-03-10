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
    // Approach 1:- using two pass approach with hashmap
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

    // Approach 2:- without using extra space
    Node* copyRandomListNew(Node* head) {
        // step 1: copy the node and insert them in-between
        Node* curr = head;
        while (curr != nullptr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }

        // step 2: connect the random pointers
        curr = head;
        while (curr != nullptr) {
            Node* copy = curr->next;

            if (curr->random != nullptr)
                copy->random = curr->random->next;
            else
                copy->random = nullptr;
    
            curr = curr->next->next;
        }

        // step 3: connect the next pointers
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        curr = head;
        while (curr != nullptr) {
            temp->next = curr->next;
            curr->next = curr->next->next;
            temp = temp->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};