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
    ListNode* reverse_between(ListNode* begin, ListNode* end) {
        ListNode* prev_node = begin;
        ListNode* curr_node = begin->next;
        ListNode* next_node = nullptr;
        ListNode* head = curr_node;

        while (curr_node != end) {
            next_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        begin->next = prev_node;
        head->next = curr_node;

        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* begin = &dummy;
        int i = 0;
        while (head) {
            if (++i % k == 0) {
                begin = reverse_between(begin, head->next);
                head = begin->next;
            } else {
                head = head->next;
            }
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
    head = sol.reverseKGroup(head, 2);
    std::cout << head << std::endl;

    ListNode* last;
    while (head) {
        last = head;
        head = head->next;
        delete last;
    }

    return 0;
}
