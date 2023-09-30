#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x): val(x), next(nullptr) {}

    ListNode(int x, ListNode* next): val(x), next(next) {}
};


class Solution {
 public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        int imaginary = 0;
        while (l1 || l2 || imaginary) {
            int total = imaginary;

            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }

            imaginary = total / 10;
            ListNode* new_node = new ListNode(total % 10);
            tail->next = new_node;
            tail = new_node;
        }

        return dummy->next;
    }
};


int main() {
    return 0;
}
