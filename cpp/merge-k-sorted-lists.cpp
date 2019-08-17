#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include "leetcode/list.h"

using namespace std;

class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        while(true) {
            if (l1 == NULL) {
                tail->next = l2;
                break;
            }
            if (l2 == NULL) {
                tail->next = l1;
                break;
            }
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        ListNode* result = head->next;
        delete head;
        return result;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        while(true) {
            if (lists.size() == 1) {
                return lists[0];
            }
            if (lists.size() % 2 == 1) {
                lists.push_back(NULL);
            }
            vector<ListNode* > tlists;
            for(int i = 0; i < lists.size(); i = i + 2) {
                tlists.push_back(this->merge2Lists(lists[i], lists[i+1]));
            }
            lists = tlists;
        }
    }

    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        ListNode* head = NULL;

        for(int row = 0; row < lists.size();row++) {
            head = this->merge2Lists(head, lists[row]);
        }

        return head;
    }
};

// force
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);

        ListNode* tail = head;
        while(true) {
            int min_row = -1;
            ListNode* min = NULL;

            for(int row = 0; row < lists.size(); row++) {
                ListNode* curr = lists[row];
                if (curr == NULL) {
                    continue;
                }
                if (min == NULL || curr->val < min->val) {
                    min = curr;
                    min_row = row;
                    continue;
                }
            }
            if (min == NULL) {
                break;
            }
            // cout << min_row << ":" << min->val << endl;
            tail->next = min;
            tail = tail->next;
            lists[min_row] = lists[min_row]->next;
        }
        return head->next;
    }
};

int main()
{
    Solution s;
    vector<ListNode*> v1;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(5);
    v1.push_back(head);

    head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    v1.push_back(head);

    head = new ListNode(8);
    head->next = new ListNode(9);
    v1.push_back(head);

    ListNode* result = s.mergeKLists(v1);
    

    printList(result);

    return 0;
}