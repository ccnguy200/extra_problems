#include <iostream>
using namespace std;

struct Node {
  int data;
  Node * next;
  Node (int val) : data(val), next(nullptr) {}
};

void printLinkedList (Node* head) {
  Node * curr = head;
  while (curr != nullptr) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

int main() 
{
    int size;
    cout << "Please enter the number of elements: " << endl;
    cin >> size;
    
    if (size <= 0) {
      cout << "List is empty!" << endl;
      return 0;
    }
    
    Node * head = nullptr;
    Node * tail = nullptr;
    
    cout << "Please enter " << size << " values: " << endl;
    for (int i = 0; i < size; i++) {
      int val;
      cin >> val;
      Node * newNode = new Node(val);
      if (head == nullptr) {
        head = newNode;
        tail = newNode;
      }
      else {
        tail->next = newNode;
        tail = newNode;
      }
    }
    
    printLinkedList (head);
    
    Node * curr = head;
    while (curr != nullptr) {
      Node * temp = curr;
      curr = curr->next;
      delete temp;
    }
    
    return 0;
}