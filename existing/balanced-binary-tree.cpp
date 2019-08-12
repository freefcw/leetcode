#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (this->getDepth(root, 0) != -1) {
            return true;
        }
        return false;
    }

    int getDepth(TreeNode* root, int depth) {
        if (root == NULL) {
            return depth;
        }
        depth++;
        int leftDepth = this->getDepth(root->left, depth);
        int rightDepth = this->getDepth(root->right, depth);
        if (leftDepth == -1 || rightDepth == -1) {
            return -1;
        }
        int maxDepth = leftDepth;
        if (maxDepth < rightDepth) {
            maxDepth = rightDepth;
        }
        if (abs(leftDepth - rightDepth) < 2) {
            return maxDepth;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("){") << endl;

    return 0;
}