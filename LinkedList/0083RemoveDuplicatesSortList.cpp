/*
83. Remove Duplicates from Sorted List
--------------------------------------
Input: head = [1,1,2]
Output: [1,2]
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

ListNode* deleteDuplicates(ListNode* head) {
  ListNode* first = head;
  ListNode* second = head->next == nullptr ? nullptr : head->next;

  while(second != nullptr) {
    if (first->val == second->val)
      first->next = second->next;
    else
      first = second;
    second = second->next;
  }

  return head;
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
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);

  cout << "Original list: ";
  printList(head);

  head = deleteDuplicates(head);

  cout << "List after removing duplicates: ";
  printList(head);

  // cleanup function copied from chatgpt \0_0/
  while (head) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }
}