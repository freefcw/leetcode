
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void output_list(ListNode *head) {
    ListNode *node = head;
    while(node!=NULL) {
        cout << "back2:" << node->val << endl;
        node = node->next;
    }
}