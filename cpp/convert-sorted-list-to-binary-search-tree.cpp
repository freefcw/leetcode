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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        vector<int> nums;
        while(true) {
            nums.push_back(head->val);
            head = head->next;
            if (head == NULL) {
                break;
            }
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


int main()
{
    Solution s;
    s.sortedListToBST();
    
    return 0;
}