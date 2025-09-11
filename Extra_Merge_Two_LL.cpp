#include <iostream>
using namespace std;

struct ListNode {
  int data;
  ListNode* next;
  ListNode() : data(0), next(nullptr) {}
  ListNode (int val) : data(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : data(val), next(next) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list1 == nullptr) { return nullptr; }
    if (list1 == nullptr) { return list2; }
    if (list2 == nullptr) { return list1; }
        
    ListNode* newLL = new ListNode(0);
    ListNode* curr = newLL;
  
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->data < list2->data) {
        curr->next = list1;
        list1 = list1->next;
      }
      else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }
  
    while (list1 != nullptr) {
      curr->next = list1;
    }
    while (list2 != nullptr) {
      curr->next = list2;
    }
  
    return newLL->next;
  }
};