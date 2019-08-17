#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int sum;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        this->walk(root, false);

        return this->sum;
    }

    void walk(TreeNode* root, bool isLeft) {
        if (isLeft && root->left == NULL && root->right == NULL) {
            this->sum += root->val;
        }
        if (root->left != NULL) {
            this->walk(root->left, true);
        }
        if (root->right != NULL) {
            this->walk(root->right, false);
        }
    }
};

int main()
{
    Solution s;

    return 0;
}