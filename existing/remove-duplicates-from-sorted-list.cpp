
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *current = head;
        while(true) {
            if (current == NULL || current->next == NULL) {
                break;
            }
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution s;

    return 0;
}