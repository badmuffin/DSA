/*
203. Remove Linked List Element
-------------------------------
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Input: head = [7,7,7,7], val = 7
Output: []
*/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
  if (head == nullptr) return nullptr;

  ListNode* dummy = new ListNode(0, head);
  ListNode* prev = dummy;
  ListNode* curr = head;

  while(curr != nullptr) {
    if (curr->val == val)
      prev->next = curr->next;
    else
      prev = curr;
    curr = curr->next;
  }

  return dummy->next;
}

void printList(ListNode* head) {
  ListNode* temp = head;

  while(temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(3);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(4);

  head = removeElements(head, 3);

  printList(head);

  while(head) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }


  return 0;
}