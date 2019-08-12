#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
private:
    int maxDepth;
    int n;
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL) {
            return head;
        }
        this->n = n;
        this->walk(head, 1);
        if (this->maxDepth == n) {
            return head->next;
        }
        return head;
    }

    void walk(ListNode* head, int depth) {
        if (head == NULL) {
            this->maxDepth = depth - 1;
            return;
        }

        this->walk(head->next, depth + 1);

        if (depth == this->maxDepth - n) {
            head->next = head->next->next;
        }
    }
};

int main()
{
    Solution s;
    int nums[] = {0};
    vector<int> vn(nums, nums + 1);

    vector<int> r2 = s.addToArrayForm(vn, 0);
    cout << "------" << endl;
    for (int i = 0; i < r2.size(); i++)
    {
        cout << r2[i] << endl;
    }
    

    return 0;
}