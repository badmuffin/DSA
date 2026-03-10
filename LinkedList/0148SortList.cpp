/*
148. Sort List - Medium
-----------------------
Given the head of a linked list, return the list after sorting it in ascending order.
*/

#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {};
  ListNode(int x) : val(x), next(nullptr) {};
  ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution
{
public:
  ListNode *sortList(ListNode *head)
  {
    return mergeSort(head);
  }

private:
  ListNode *mergeSort(ListNode *head)
  {
    if (head == nullptr or head->next == nullptr)
      return head;

    // find the mid value
    ListNode *mid = findMid(head);

    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = nullptr; // break the link

    // sort both the halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both the sorted list
    return merge(left, right);
  }

  ListNode *merge(ListNode *left, ListNode *right)
  {
    if (left == nullptr)
      return right;
    if (right == nullptr)
      return left;

    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy; // for traversing

    while (left and right)
    {
      if (left->val <= right->val)
      {
        temp->next = left;
        temp = left;
        left = left->next;
      }
      else
      {
        temp->next = right;
        temp = right;
        right = right->next;
      }
    }

    // add remaining element, if any
    while (left)
    {
      temp->next = left;
      temp = left;
      left = left->next;
    }

    while (right)
    {
      temp->next = right;
      temp = right;
      right = right->next;
    }

    return dummy->next;
  }

  ListNode *findMid(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast and fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};