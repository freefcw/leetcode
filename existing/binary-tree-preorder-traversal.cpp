#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> paths;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return this->paths;
        }
        this->walk(root);
        return this->paths;
    }

    void walk(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        this->paths.push_back(root->val);
        this->walk(root->left);
        this->walk(root->right);
    }
};

int main()
{
    Solution s;

    return 0;
}