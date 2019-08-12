#include <cstdio>
#include <vector>
#include <map>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        return this->convert(nums, 0, nums.size());
    }

    TreeNode* convert(vector<int>& nums, int start, int end) {
        int mid = (end + start) / 2;
        // cout << mid << " = " << start << ":" << end << endl;
        TreeNode *node = new TreeNode(nums[mid]);
        if (mid > start) {
            node->left = this->convert(nums, start, mid);
        }
        if (mid + 1 < end) {
            node->right = this->convert(nums, mid + 1, end);
        }
        
        return node;
    }
};

class Solution2 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        int mid = nums.size() / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        if (mid > 0) {
            vector<int> lefts;
            for(int i = 0; i < mid; i++) {
                lefts.push_back(nums[i]);
            }
            node->left = this->sortedArrayToBST(lefts);
        }
        if (mid < nums.size() - 1) {
            vector<int> rights;
            for(int i = mid + 1; i < nums.size(); i++) {
                rights.push_back(nums[i]);
            }
            node->right = this->sortedArrayToBST(rights);
        }
        
        return node;
    }
};

int main()
{
    Solution s;
    int n[] = {-10,-3,0,5,9};
    vector<int> v(n, n + 5);
    s.sortedArrayToBST(v);
    
    return 0;
}