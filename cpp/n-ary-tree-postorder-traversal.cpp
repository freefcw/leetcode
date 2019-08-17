#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> paths;
public:
    vector<int> postorder(Node* root) {
        if (root == NULL) {
            return this->paths;
        }
        this->walk(root);
        return this->paths;
    }

    void walk(Node *root) {
        if (root == NULL) {
            return;
        }
        for (int i = 0; i < root->children.size(); ++i)
        {
            this->walk(root->children[i]);
        }
        this->paths.push_back(root->val);
    }
};

int main()
{
    Solution s;

    return 0;
}