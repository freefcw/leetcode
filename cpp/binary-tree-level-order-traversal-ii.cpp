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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) {
            return this->nodes;
        }
        this->walk(root, 0);
        vector<vector<int> > result(this->nodes.rbegin(), this->nodes.rend());
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