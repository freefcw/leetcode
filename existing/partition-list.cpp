#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* largeListHead = NULL;
        ListNode* largeListTail = NULL;
        ListNode* current = head;
        ListNode* smallHead = NULL;
        ListNode* prefore = NULL;

        while(true) {
            if (current == NULL) {
                break;
            }
            if (current->val >= x) {
                if (largeListHead == NULL) {
                    largeListHead = current;
                    largeListTail = current;
                } else {
                    largeListTail->next = current;
                    largeListTail = largeListTail->next;
                }
                current = current->next;
                largeListTail->next = NULL;
            } else {
                if (prefore == NULL) {
                    smallHead = current;
                    prefore = current;
                } else {
                    prefore->next = current;
                    prefore = prefore->next;
                }
                current = current->next;
                prefore->next = NULL;
            }
        }
        if (prefore == NULL) {
            return largeListHead;
        }
        if (largeListHead != NULL)  {
            prefore->next = largeListHead;
        }

        return smallHead;
    }
};

int main()
{
    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    // head->next->next->next->next->next->next = new ListNode(5);
    
    ListNode* result = s.partition(head, 9);
    while(result != NULL) {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}