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
    vector<int> inorderTraversal(TreeNode* root) {
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
        this->walk(root->left);
        this->paths.push_back(root->val);
        this->walk(root->right);
    }
};

int main()
{
    Solution s;

    return 0;
}