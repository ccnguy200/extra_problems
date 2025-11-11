#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node (int x) : data(x), left(nullptr), right(nullptr) {}
};

bool isIdentical (Node* tree1, Node* tree2) {
  if (tree1 == nullptr && tree2 == nullptr) return true;
  return (tree1 && tree2) && (tree1->data == tree2->data) 
                          && isIdentical (tree1->left, tree2->left)
                          && isIdentical (tree1->right, tree2->right);
}

int main() 
{
    Node* tree1 = nullptr;
    tree1 = new Node(15);
    tree1->left = new Node(10);
    tree1->right = new Node(20);
    tree1->left->left = new Node(8);
    tree1->left->right = new Node(12);
    tree1->right->left = new Node(16);
    tree1->right->right = new Node(25);
    
    Node* tree2 = nullptr;
    tree2 = new Node(15);
    tree2->left = new Node(10);
    tree2->right = new Node(20);
    tree2->left->left = new Node(8);
    tree2->left->right = new Node(12);
    tree2->right->left = new Node(16);
    tree2->right->right = new Node(26);
    
    if (isIdentical(tree1, tree2)) cout << "Both trees are identical" << endl;
    else cout << "Both trees are NOT identical" << endl;
    
    return 0;
}