#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include "leetcode/tree.h"

using namespace std;

class Solution {
private:
    int sum;
    int minimum;
    int maximum;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        this->sum = 0;
        this->minimum = L;
        this->maximum = R;
        this->findTree(root);

        return this->sum;
    }

    void findTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->val <= this->maximum 
        && root->val >= this->minimum) {
            this->sum += root->val;
        }
        if (root->val > this->minimum) {
            this->findTree(root->left);
        }
        if (root->val < this->maximum) {
            this->findTree(root->right);
        }
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(18);

    cout << s.rangeSumBST(root,7,15) << endl;
    
    return 0;
}