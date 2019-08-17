#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int> > nodes;
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        this->walk(root, 0);
        for (int i = 0; i < this->nodes.size(); ++i)
        {
            result.push_back(this->nodes[i].back());
        }

        return result;
    }

    void walk(TreeNode* root, int level) {
        if (root != NULL) {
            if (this->nodes.size() <= level) {
                this->nodes.push_back(vector<int>());
            }
            this->nodes[level].push_back(root->val);
        }
        if (root->left != NULL) {
            this->walk(root->left, level + 1);
        }
        if (root->right != NULL) {
            this->walk(root->right, level + 1);
        }
    }
};

int main()
{
    Solution s;

    return 0;
}