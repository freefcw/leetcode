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
    vector<int> postorderTraversal(TreeNode* root) {
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
        this->walk(root->right);
        this->paths.push_back(root->val);
    }
};

int main()
{
    Solution s;

    return 0;
}