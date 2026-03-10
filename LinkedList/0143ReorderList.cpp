/*
143. Reorder List
-----------------------
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
------------------------
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;

        // use slow and fast pointer to find mid
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of the list
        ListNode* second = slow->next;
        slow->next = nullptr; // split the list
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(second != nullptr) {
            next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // merge the list
        ListNode* first = head;
        second = prev;
        while(second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // create linked list [1,2,3,4,5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}

// OUTPUT 
/*
    Original list: 1 -> 2 -> 3 -> 4 -> 5
    Reordered list: 1 -> 5 -> 2 -> 4 -> 3
*/