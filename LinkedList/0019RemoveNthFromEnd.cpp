/*
19 Remove nth node from end of list
-----------------------------------
Given the head of a linked list, remove the nth node from the end
of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = dummy;

        while (n >= 0 && right != nullptr) {
            right = right->next;
            n--;
        }

        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        ListNode* nodeToBeDeleted = left->next;
        left->next = nodeToBeDeleted->next;

        delete(nodeToBeDeleted);

        return dummy->next;
    }
};