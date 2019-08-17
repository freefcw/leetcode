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
    ListNode* rotateRight(ListNode* head, int k) {
        int depth = this->getDepth(head, 0);
        if (depth == 0 || k == 0) {
            return head;
        }
        // cout << "depth: " << depth << endl;
        k = k % depth;
        if (k == 0) {
            return head;
        }
        int rk = depth - k;
        ListNode* preNode = this->getKNode(head, 0, rk);
        ListNode* node = preNode->next;
        ListNode* last = preNode->next;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = head;
        preNode->next = NULL;
        return node;
    }

    ListNode* getKNode(ListNode *head, int d, int rk) {
        if (d + 1 == rk) {
            return head;
        }
        if (head == NULL) {
            return NULL;
        }
        return this->getKNode(head->next, d+1, rk);
    }

    int getDepth(ListNode* head, int depth) {
        if (head == NULL) {
            return depth;
        }
        return this->getDepth(head->next, depth + 1);
    }
};

int main()
{
    Solution s;
    ListNode *head, *cursor;
    head = new ListNode(0);
    cursor = head;
    int nums[] = {1};
    for(int i = 0; i < 1; i++) {
        cursor->next = new ListNode(nums[i]);
        cursor = cursor->next;
    }

    ListNode *ret = s.rotateRight(head->next, 1);
    while(ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }

    return 0;
}