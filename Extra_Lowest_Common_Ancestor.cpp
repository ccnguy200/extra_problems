#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) return new Node(data);
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* lca(Node* root, int v1, int v2) {
    if (root == nullptr) return nullptr;

    if (v1 < root->data && v2 < root->data) {
        return lca(root->left, v1, v2);
    }
    if (v1 > root->data && v2 > root->data) {
        return lca(root->right, v1, v2);
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;

    while (n--) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    int v1, v2;
    cin >> v1 >> v2;

    Node* result = lca(root, v1, v2);
    cout << "Lowest common ancestor of " << v1 << " and " << v2 << " is " << result->data << endl;

    return 0;
}
