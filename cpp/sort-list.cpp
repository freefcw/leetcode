#include <iostream>
#include <map>
#include <vector>
#include "leetcode/list.h"

using namespace std;

class Solution {
private:
    ListNode* anchor;
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        this->anchor = new ListNode(-1);
        this->anchor->next = head;
        ListNode* prev = this->anchor->next;
        ListNode* current = prev->next;
        while(true) {
            if (current == NULL) {
                break;
            }
            // cout << current->val << endl;
            if (current->val >= prev->val) {
                prev = prev->next;
                current = current->next;
                continue;
            }
            prev->next = current->next;
            this->insert(current);
            current = prev->next;
        }
        return this->anchor->next;
    }

    void insert(ListNode* current) {
        ListNode* point = this->anchor->next;
        ListNode* pprev = this->anchor;
        
        while(true) {
            if (current == NULL 
                || point == NULL || point == current ) {
                break;
            }
            if (current->val <= point->val) {
                pprev->next = current;
                current->next = point;
                return;
            }
            
            pprev = pprev->next;
            point = point->next;
        }
    }
};

int main() {
    Solution s;
    int nums[] = {-84,142,41,-17,-71,170,186,183,-21,-76,76,10,29,81,112,-39,-6,-43,58,41,111,33,69,97,-38,82,-44,-7,99,135,42,150,149,-21,-30,164,153,92,180,-61,99,-81,147,109,34,98,14,178,105,5,43,46,40,-37,23,16,123,-53,34,192,-73,94,39,96,115,88,-31,-96,106,131,64,189,-91,-34,-56,-22,105,104,22,-31,-43,90,96,65,-85,184,85,90,118,152,-31,161,22,104,-85,160,120,-31,144,115, 9999};
    int index = 0;
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;
    while(true) {
        if (nums[index] == 9999) {
            break;
        }
        // cout << nums[index] << endl;
        tail->next = new ListNode(nums[index]);
        tail = tail->next;
        index++;
    }

    
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(1);
    // head->next->next->next = new ListNode(3);

    ListNode* result = s.sortList(head->next);
    printList(result);
}