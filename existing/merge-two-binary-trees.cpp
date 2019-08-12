#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }
        TreeNode* mt = new TreeNode(0);
        this->mergeTree(mt, t1, t2);

        return mt;
    }

    void mergeTree(TreeNode* mt, TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            mt->val = t2->val;
            mt->left = t2->left;
            mt->right = t2->right;
            return;
        }
        if (t2 == NULL) {
            mt->val = t1->val;
            mt->left = t1->left;
            mt->right = t1->right;
            return;
        }

        mt->val = t1->val + t2->val;

        if (t1->left != NULL || t2->left != NULL) {
            mt->left = new TreeNode(0);
            this->mergeTree(mt->left, t1->left, t2->left);
        }

        if (t1->right != NULL || t2->right != NULL) {
            mt->right = new TreeNode(0);
            this->mergeTree(mt->right, t1->right, t2->right);
        }
    }
};

int main()
{
    Solution s;

    return 0;
}