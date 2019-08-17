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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        while(true) {
            if (first == NULL || second == NULL) {
                return first;
            }
            first = first->next;
            second = second->next;
            if (second == NULL) {
                return first;
            } else {
                second = second->next;
            }
        }
    }
};
