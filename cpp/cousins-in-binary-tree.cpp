#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;
class Solution {
private:
    int x;
    int y;
    int x_level;
    int y_level;
    TreeNode *x_node;
    TreeNode *y_node;
    TreeNode *x_parent;
    TreeNode *y_parent;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        this->findNode(root, NULL, 0);
        if (this->x_level == this->y_level) {
            if (this->x_parent != this->y_parent
                && this->x_parent != this->y_node
                && this->y_parent != this->x_node)
            {
                return true;
            }
        }
        return false;
    }

    void findNode(TreeNode* root, TreeNode* parent, int depth)
    {
        if (root == NULL) {
            return;
        }
        if (this->x_node != NULL && this->y_node != NULL) {
            return;
        }
        if (root->val == this->x) {
            this->x_level = depth;
            this->x_parent = parent;
            this->x_node = root;
        }
        if (root->val == this->y) {
            this->y_node = root;
            this->y_level = depth;
            this->y_parent = parent;
        }
        this->findNode(root->left, root, depth+1);
        this->findNode(root->right, root, depth+1);
    }
};

int main()
{
    Solution s;
    
    
    return 0;
}