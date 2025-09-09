#include <iostream>
using namespace std;

struct Node {
  int data;
  Node * next;
  Node (int val) : data(val), next(nullptr) {}
};

Node * insertNodeAtTail (Node * head, int data) {
  Node * newNode = new Node(data);
  if (head == nullptr) {
    return newNode;
  }
  Node * curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = newNode;
  return head;
}

int main() 
{
    int size;
    cout << "Please enter the number of elements: " << endl;
    cin >> size;
    
    if (size <= 0) {
      cout << "Please enter a valid size!" << endl;
      return 0;
    }
    
    Node * head = nullptr;
    for (int i = 0; i < size; i++) {
      int val;
      cin >> val;
      head = insertNodeAtTail (head, val);
    }
    
    Node * temp = head;
    while (temp != nullptr) {
      cout << temp->data << endl;
      temp = temp->next;
    }
    
    Node * curr = head;
    while (curr != nullptr) {
      Node * temp = curr;
      curr = curr->next;
      delete temp;
    }
    
    return 0;
}