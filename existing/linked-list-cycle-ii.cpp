
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        std::map<ListNode*, int> sentinels;
        ListNode *current;
        current = head;
        while(true) {
            if (current == NULL) {
                return NULL;
            }
            if (sentinels.find(current) != sentinels.end()) {
                return current;
            }
            sentinels[current] = 1;
            current = current->next;
        }
        return NULL;
    }
};

/**
    自己做cache
*/
class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        vector<ListNode *> sentinels;
        ListNode *current;
        current = head;
        while(true) {
            if (current == NULL) {
                return NULL;
            }
            // cout << "loop:" << current << endl;
            for (std::vector<ListNode *>::iterator node = sentinels.begin(); node != sentinels.end(); ++node)
            {
                if (*node == NULL) {
                    break;
                }
                // cout << "sentinel:" << *node << endl;
                if (*node == current) {
                    return current;
                }
            }
            sentinels.push_back(current);
            current = current->next;
        }
        return NULL;
    }
};

ListNode* buildList(int nums[], int total, int pos)
{
    ListNode *posNode;
    ListNode *head;
    if (total == 0) {
        return head;
    }
    head = new ListNode(nums[0]);
    if (pos == 0) {
        head->next = head;
        return head;
    }
    ListNode *current;
    current = head;
    for (int i = 1; i < total; ++i)
    {
        current->next = new ListNode(nums[i]);
        // cout << current << ":" << current->val << endl;
        if (i == pos) {
            posNode = current->next;
        }
        current = current->next;
    }
    current->next = posNode;

    return head;
}

int main()
{
    Solution s;
    int nums[] = {1,2,3,4,5};
    ListNode *head = buildList(nums, 5, 4);


    cout << s.detectCycle(head) << endl;


    return 0;
}