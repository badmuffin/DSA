/*
LC 2: Add Two Numbers (represented by linked list)

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


Input: l1 = [0], l2 = [0]
Output: [0]

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry > 0) {
            int num1 = l1 != nullptr ? l1->val : 0;
            int num2 = l2 != nullptr ? l2->val : 0;

            int total = num1 + num2 + carry;
            carry = total/10;

            ListNode* temp = new ListNode(total%10);
            dummy->next = temp;
            dummy = dummy->next;

            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }

        return ans->next;
    }
};