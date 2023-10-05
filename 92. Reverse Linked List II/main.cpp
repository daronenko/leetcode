#include <iostream>
#include <vector>


struct ListNode {
    int val;
    ListNode* next;

    ListNode(): val(0), next(nullptr) {}

    explicit ListNode(int x): val(x), next(nullptr) {}

    ListNode(int x, ListNode* next): val(x), next(next) {}
};


std::ostream& operator << (std::ostream& out, ListNode* node) {
    ListNode* curr = node;
    while (curr) {
        out << curr->val << ' ';
        curr = curr->next;
    }

    return out;
}


class Solution {
 public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev_node = &dummy;

        for (int i = 0; i < left - 1; ++i) {
            prev_node = prev_node->next;
        }

        ListNode* curr_node = prev_node->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* next_node = curr_node->next;
            curr_node->next = next_node->next;
            next_node->next = prev_node->next;
            prev_node->next = next_node;
        }

        return dummy.next;
    }
};


int main() {
    std::vector<int> nums{1, 2, 3, 4, 5};
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (const int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    ListNode* head = dummy.next;

    Solution sol;
    sol.reverseBetween(head, 2, 4);

    ListNode* last;
    while (head) {
        last = head;
        head = head->next;
        delete last;
    }

    return 0;
}
