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

void printList(ListNode *head) {
    while(true) {
        if (head == NULL) {
            break;
        }
        cout << head->val << endl;
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* current = head->next;
        head->next = NULL;
        ListNode* next = NULL; 
        while(true) {
            if (current == NULL) {
                return head;
            }
            next = current->next;
            current->next = head;
            head = current;
            current = next;
        }
    }

    void reorderList(ListNode* head) {
        if (head == NULL) {
            return;
        }
        ListNode* current1 = head;
        ListNode* current2 = head;
        while(true) {
            if (current2->next != NULL && current2->next->next != NULL) {
                current2 = current2->next->next;
            } else {
                break;
            }
            current1 = current1->next;
        }

        // printList(head);
        // printList(current1);
        ListNode* newhead = this->reverseList(current1->next);
        current1->next = NULL;
        // printList(newhead);

        current1 = head;
        current2 = newhead;


        while(true) {
            if (current1 == NULL || current2 == NULL) {
                break;
            }
            ListNode* t1 = current1->next;
            current1->next = current2;
            ListNode* t2 = current2->next;
            current2->next = t1;
            current1 = t1;
            current2 = t2;
        }
        // printList(head);
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = NULL;
    // ListNode* result = s.reverseList(head);
    s.reorderList(head);

    return 0;
}