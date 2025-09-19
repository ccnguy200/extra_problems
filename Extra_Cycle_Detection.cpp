#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

int has_cycle(Node* head) {
  if (head == nullptr) { return 0; }
  Node* slow = head;
  Node* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) { return 1; }
  }
  return 0;
}

int main() 
{
    // Input 1: 1 -> NULL
    Node* head1 = new Node(1);
    // Output 1: 0
    cout << has_cycle(head1) << endl;
    
    // Input 2: 1 -> 2 -> 3 -> 2 -> NULL
    Node* head2 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    
    head2->next = node2;
    node2->next = node3;
    node3->next = node2;
    // Output2: 1 
    cout << has_cycle(head2) << endl;
    
    return 0;
}