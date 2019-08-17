#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *left = root->left;
        root->left = this->invertTree(root->right);
        root->right = this->invertTree(left);

        return root;
    }
};

int main()
{
    Solution s;
    TreeNode *head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);
    head->right = new TreeNode(7);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(9);

    head = s.invertTree(head);
    cout << head->val << endl;
    cout << head->left->val << ":" << head->right->val << endl;
    cout << head->left->left->val << ":" << head->left->right->val << endl;
    cout << head->right->left->val << ":" << head->right->right->val << endl;
    return 0;
}