#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

// 中序遍历是一个升序的序列
class Solution {
private:
    int max;
    int current_count;
    int current_number;
    vector<int> numbers;
public:
    vector<int> findMode(TreeNode* root) {
        this->max = 0;
        this->current_count = 0;
        this->current_number = -1;
        this->walk(root);

        return this->numbers;
    }

    void walk(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        this->walk(root->left);

        if (this->current_number == -1) {
            this->current_number = root->val;
            this->current_count = 1;
            this->max = 1;
            this->numbers.push_back(this->current_number);
        } else {
            // cout << root->val << ":" << this->current_number << "|" << this->current_count << endl;
            if (root->val != this->current_number) {
                // reset
                this->current_number = root->val;
                this->current_count = 1;
            } else {
                this->current_count++;
            }
            if (this->current_count > this->max) {
                this->numbers.clear();
                this->max = this->current_count;
            }
            if (this->numbers.size() == 0) {
                this->numbers.push_back(this->current_number);
            }
            if (this->current_count >= this->max
                && this->current_number != this->numbers.back()) {
                this->numbers.push_back(this->current_number);
            }
        }

        this->walk(root->right);
    }
};

class Solution2 {
private:
    vector<int> numbers;
    vector<int> counts;
public:
    vector<int> findMode(TreeNode* root) {
        this->walk(root);
        vector<int> result;
        int max = 0;
        for (int i = 0; i < this->numbers.size(); ++i)
        {
            if (this->counts[i] > max) {
                result.clear();
                result.push_back(this->numbers[i]);
                max = this->counts[i];
                continue;
            }
            if (this->counts[i] == max) {
                result.push_back(this->numbers[i]);
                continue;
            }
        }
        return result;
    }

    void walk(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        int pos = this->findPos(root->val);
        this->counts[pos]++;
        this->walk(root->left);
        this->walk(root->right);
    }
    int findPos(int num) {
        int index = -1;
        for (int i = 0; i < this->numbers.size(); ++i)
        {
            if (this->numbers[i] == num) {
                return i;
            }
        }
        if (index == -1) {
            this->numbers.push_back(num);
            this->counts.push_back(0);
        }
        return this->numbers.size() - 1;
    }
};

int main()
{
    Solution s;

    return 0;
}