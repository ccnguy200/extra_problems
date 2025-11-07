#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int maxDiameter = 0;
    int DFS(TreeNode* node) {
        if (node == NULL) return 0;
        int leftHeight = DFS(node->left);
        int rightHeight = DFS(node->right);
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root);
        return maxDiameter;
    }
};

int main () {
  TreeNode* root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);
  
  TreeNode* root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  
  Solution sol1, sol2;
  cout << "Diameter: " << sol1.diameterOfBinaryTree(root1) << endl;
  cout << "Diameter: " << sol2.diameterOfBinaryTree(root2) << endl;
  
  
  return 0;
}
