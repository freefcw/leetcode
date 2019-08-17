
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return this->doMinDepth(root);
    }

    int doMinDepth(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        if (root->left == NULL) {
            return this->doMinDepth(root->right) + 1;
        }
        if (root->right == NULL) {
            return this->doMinDepth(root->left) + 1;
        }
        int left = this->minDepth(root->left);
        int right = this->minDepth(root->right);
        if (left > right) {
            return right + 1;
        }

        return left + 1;
    }
};