#include <cstdio>
#include <vector>
#include <map>
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int max = 0;
        if (root->left) {
            int depth = this->maxDepth(root->left);
            if (depth > max) {
                max = depth;
            }
        }
        if (root->right) {
            int depth = this->maxDepth(root->right);
            if (depth > max) {
                max = depth;
            }
        }
        return 1 + max;
    }
};

int main()
{
    Solution s;
    int nums[] = {2,2,1,1,1,2,2};
    vector<int> vn(nums, nums + 7);
    cout << s.majorityElement(vn) << endl;

    return 0;
}