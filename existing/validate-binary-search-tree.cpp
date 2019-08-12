#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return this->helper(root, -1, -1);
    }

    bool helper(TreeNode *root, int higher, int lower)
    {
        if (root == NULL) {
            return true;
        }
        if (higher != -1 && root->val >= higher) {
            return false;
        }
        if (lower != -1 && root->val <= lower) {
            return false;
        }
        if (!this->helper(root->left, root->val, lower)) {
            return false;
        }
        if (!this->helper(root->right, higher, root->val)) {
            return false;
        }
        return true;
    }
};

// inorder
class Solution2 {
private:
    int last;
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        this->last = -1;
        return this->walk(root);
    }

    bool walk(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (!this->walk(root->left)) {
            return false;
        }
        if (this->last != -1 && root->val <= this->last) {
            return false;
        }

        this->last = root->val;
        if (!this->walk(root->right)) {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;

    return 0;
}