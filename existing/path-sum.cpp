
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(TreeNode *root, int pos, vector<int> nums) {
    if (pos > nums.size()) {
        return NULL;
    }
    root = new TreeNode(nums[i]);
    buildTree(root->left, pos * 2, nums);
    buildTree(root->right, pos * 2 + 1, nums);
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL
         && root->right == NULL
         && root->val == sum) {
            return true;
        }
        if (root->left && this->hasPathSum(root->left, sum - root->val)) {
            return true;
        }
        if (root->right && this->hasPathSum(root->right, sum - root->val)) {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    TreeNode root;

    return 0;
}