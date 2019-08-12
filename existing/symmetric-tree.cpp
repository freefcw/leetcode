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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL) {
            return false;
        }

        if (left->val != right->val) {
            return false;
        }

        return this->isMirror(left->right, right->left)
         && this->isMirror(left->left, right->right);
    }
};



int main()
{
    Solution s;
    
    
    return 0;
}