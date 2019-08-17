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

class MyLinkedList {
private:
    ListNode *head;
    ListNode *tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->head = new ListNode(-1);
        this->tail = this->head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* current = this->head->next;
        int pos = 0;
        while(true) {
            if (current == NULL) {
                return -1;
            }
            if (pos == index) {
                return current->val;
            }
            current = current->next;
            pos++;
        }

        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);

        node->next = this->head->next;
        this->head->next = node;
        if (this->tail == this->head) {
            this->tail = this->head->next;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        this->tail->next = node;
        this->tail = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* node = new ListNode(val);
        ListNode* current = this->head;
        if (index < 0) {
            index = 0;
        }
        int pos = 0;
        while(true) {
            if (current == NULL) {
                return;
            }
            if (pos == index) {
                if (this->tail == current) {
                    this->tail = node;
                }
                node->next = current->next;
                current->next = node;
            }
            current = current->next;
            pos++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* current = this->head;
        int pos = 0;
        while(true) {
            if (current == NULL) {
                return;
            }
            if (pos == index) {
                if (current->next == NULL) {
                    return;
                }
                ListNode* target = current->next;
                if (target == this->tail) {
                    this->tail = current;
                }
                current->next = target->next;
                delete target;
                return;
            }
            current = current->next;
            pos++;
        }
    }
};

void printLinkedList(MyLinkedList *list) {
    int pos = 0;
    while(true) {
        int val = list->get(pos);
        if (val == -1) {
            cout << endl;
            return;
        }
        cout << val << "-";
        pos++;
    }
}

int main()
{
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(7);
    linkedList->addAtHead(2);
    linkedList->addAtHead(1);
    printLinkedList(linkedList);
    linkedList->addAtIndex(3,0);
    printLinkedList(linkedList);
    linkedList->deleteAtIndex(2);
    printLinkedList(linkedList);
    linkedList->addAtHead(6);
    printLinkedList(linkedList);
    linkedList->addAtTail(4);
    printLinkedList(linkedList);
    cout << linkedList->get(4) << endl;
    linkedList->addAtHead(4);
    linkedList->addAtIndex(5, 0);
    linkedList->addAtHead(6);
    
    // printLinkedList(linkedList);
    // // linkedList->addAtHead(1);
    // printLinkedList(linkedList);
    // linkedList->addAtTail(3);
    // printLinkedList(linkedList);
    // linkedList->addAtIndex(1, 2);  // linked list becomes 1->2->3
    // printLinkedList(linkedList);
    // cout << linkedList->get(1) << endl;            // returns 2
    // linkedList->deleteAtIndex(0);  // now the linked list is 1->3
    // printLinkedList(linkedList);
    // linkedList->addAtIndex(0, 9);  // linked list becomes 1->2->3
    // printLinkedList(linkedList);
    // linkedList->deleteAtIndex(2);  // now the linked list is 1->3
    // cout << linkedList->get(1) << endl;            // returns 3
    // cout << linkedList->get(2) << endl;            // returns 3
    // printLinkedList(linkedList);
    // linkedList->addAtTail(5);
    // printLinkedList(linkedList);

    return 0;
}