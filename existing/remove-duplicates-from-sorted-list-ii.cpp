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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* current;
        current = head;
        head = NULL;
        bool isCurrentDupilicated = false;
        ListNode* lastNode = NULL;
        while(true) {
            if (current->next == NULL) {
                // cout << isCurrentDupilicated << endl
                // if (lastNode != NULL) {
                //     cout << lastNode->val << "|" << lastNode->next << endl;
                // }
                // cout << current->val << "|" << head << endl;
                if (isCurrentDupilicated && lastNode != NULL) {
                    lastNode->next = NULL;
                }
                if (!isCurrentDupilicated && head == NULL) {
                    head = current;
                }
                break;
            }
            // cout << current->val << ":" << current->next << endl;
            if (current->val != current->next->val) {
                if (!isCurrentDupilicated) {
                    if (head == NULL) {
                       head = current;
                    }
                    lastNode = current;
                } else {
                    if (lastNode != NULL) {
                        lastNode->next = current->next;
                    }
                    isCurrentDupilicated = false;
                }
                current = current->next;
            } else {
                isCurrentDupilicated = true;
                current->next = current->next->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    
    ListNode* result = s.deleteDuplicates(head);
    while(result != NULL) {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}