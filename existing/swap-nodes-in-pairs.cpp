#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *next;
        next = head->next;
        head->next = next->next;
        next->next = head;

        head->next = this->swapPairs(head->next);

        return next;
    }
};


int main()
{
    Solution s;


    return 0;
}