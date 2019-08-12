#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode *head;
        ListNode *point;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        point = head;
        while(true) {
            if (l1 == NULL) {
                point->next = l2;
                break;
            }
            if (l2 == NULL) {
                point->next = l1;
                break;
            }
            if (l1->val <= l2->val) {
                point->next = l1;
                l1 = l1->next;
            } else {
                point->next = l2;
                l2 = l2->next;
            }
            point = point->next;
        }
        return head;
    }
};
int main()
{
    Solution s;


    return 0;
}