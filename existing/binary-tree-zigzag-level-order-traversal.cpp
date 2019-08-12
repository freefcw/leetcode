#include <iostream>
#include <map>
#include <vector>
#include "leetcode/tree.h"

using namespace std;

class Solution{
private:
    vector<vector<int> > values;
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        this->walk(root, 0);
        for(int i = 0; i < this->values.size();i++) {
            if (this->values.size() > 0) {
                if (i % 2 == 1) {
                    this->values[i] = this->reverse(this->values[i]);
                }
            }
        }
        return this->values;
    }

    vector<int> reverse(vector<int> values)
    {
        int len = values.size();
        for(int k = 0; k < values.size(); k++) {
            if (k >= len - k - 1) {
                break;
            }
            int t = values[k];
            values[k] = values[len - k - 1];
            values[len - k - 1] = t;
        }

        return values;
    }

    void walk(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (this->values.size() == level) {
            vector<int> nodes;
            this->values.push_back(nodes);
        }
        this->values[level].push_back(root->val);
        this->walk(root->left, level + 1);
        this->walk(root->right, level + 1);
    }
};

int main() {
    Solution s;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int> > result = s.zigzagLevelOrder(root);
    for(int i = 0; i < result.size(); i++) {
        for (int k = 0; k < result[i].size(); k++) {
            cout << result[i][k] << " ";
        }
        cout << endl;
    }
}