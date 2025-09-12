#include <iostream>
using namespace std;

struct ListNode {
  int data;
  ListNode* next;
  ListNode() : data(0), next(nullptr) {}
  ListNode(int val) : data(val), next(nullptr) {}
  ListNode (int val, ListNode* next) : data(val), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr != nullptr) {
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }
        return prev;
    }
};

void printList (ListNode* head) {
  if (head == nullptr) { return; }
  ListNode* curr = head;
  while (curr != nullptr) {
    cout << curr->data;
    if (curr->next != nullptr) {
      cout << " -> ";
    }
    curr = curr->next;
  }
}

int main() 
{
  int size;
  cin >> size;

  ListNode* head = nullptr;
  ListNode* tail = nullptr;

  for (int i = 0; i < size; i++) {
    int val;
    cin >> val;

    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
  }

  cout << endl << "Original list: ";
  printList(head);
  
  Solution sol;
  head = sol.reverseList(head);

  cout << endl << "Reversed list: ";
  printList(head);
  
  return 0;
}