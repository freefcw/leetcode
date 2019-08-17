#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    int value;
    int destDepth;
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        this->value = v;
        this->destDepth = d;
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }

        this->walk(root, 1);

        return root;
    }

    void walk(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level + 1 == this->destDepth) {
            TreeNode* node = new TreeNode(this->value);
            node->left = root->left;
            root->left = node;

            TreeNode* node_right = new TreeNode(this->value);
            node_right->right = root->right;
            root->right = node_right;
        } else {
            if (root->left != NULL) {
                this->walk(root->left, level + 1);
            }
            if (root->right != NULL) {
                this->walk(root->right, level + 1);
            }
        }
    }
};

int main()
{
    Solution s;

    return 0;
}