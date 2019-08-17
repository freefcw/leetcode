#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include "leetcode/list.h"

using namespace std;


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* oddHead = head->next;
        ListNode* curr1 = head;
        ListNode* curr2 = oddHead;

        while(true) {
            if (curr1 == NULL || curr2 == NULL || curr2->next == NULL) {
                break;
            }
            curr1->next = curr2->next;
            curr1 = curr1->next;

            if (curr1 == NULL) {
                break;
            }
            curr2->next = curr1->next;
            curr2 = curr2->next;
        }
        curr1->next = oddHead;

        return head;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = NULL;
    ListNode* result = s.oddEvenList(head);
    

    printList(result);

    return 0;
}