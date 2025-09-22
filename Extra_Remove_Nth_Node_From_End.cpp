#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node() : data(0), next(nullptr) {}
  Node(int val) : data(val), next(nullptr) {}
  Node(int val, Node* next) : data(val), next(next) {}
};

class Solution {
public:
    Node* removeNthFromEnd(Node* head, int n) {
        Node* tempHead = new Node(0, head);
        int length = 0;
        Node* temp = head;
        while (temp != nullptr) {
          length++;
          temp = temp->next;
        }
        int removeIndex = length-n;
        temp = tempHead;
        for (int i = 0; i < removeIndex; i++) {
          temp = temp->next;
        }
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
        Node* newHead = tempHead->next;
        delete tempHead;
        return newHead;
    }
};

void print (Node* temp) {
  while (temp != nullptr) {
    cout << temp->data;
    if (temp->next != nullptr) { cout << ","; }
    temp = temp->next;
  }
}

int main() 
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    Solution sol;
    head = sol.removeNthFromEnd(head, 2);
    cout << "Input: head = [1,2,3,4,5], n = 2" << endl << "Output: [";
    print(head);
    cout << "]" << endl;
    
    
    return 0;
}