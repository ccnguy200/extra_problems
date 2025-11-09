#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (!leftToRight)
                reverse(level.begin(), level.end());

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    
    cout << "Result 1:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl << "Result 2: " << endl;
    
    TreeNode* root2 = new TreeNode(1);

    Solution sol2;
    vector<vector<int>> result2 = sol2.zigzagLevelOrder(root2);

    for (int i = 0; i < result2.size(); i++) {
        for (int j = 0; j < result2[i].size(); j++) {
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl << "Result 3: " << endl;
    
    TreeNode* root3 = nullptr;

    Solution sol3;
    vector<vector<int>> result3 = sol3.zigzagLevelOrder(root3);

    for (int i = 0; i < result3.size(); i++) {
        for (int j = 0; j < result3[i].size(); j++) {
            cout << result3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
