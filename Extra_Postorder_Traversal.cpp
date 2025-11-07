#include <iostream>
using namespace std;

class Node {
  public:
      int data;
      Node *left;
      Node *right;
      Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
      }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        } else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    void postOrder(Node *root) {
        if (root == nullptr)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
};

int main() 
{
    Solution Sol;
    Node* root = nullptr;
    int size, data;

    cin >> size;
    while (size-- > 0) {
        cin >> data;
        root = Sol.insert(root, data);
    }
    
    Sol.postOrder(root);
    return 0;
}
