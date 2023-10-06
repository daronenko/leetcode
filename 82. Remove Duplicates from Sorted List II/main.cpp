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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev_node = &dummy;
        ListNode* curr_node = head;

        while (curr_node) {
            ListNode* next_node = curr_node->next;
            while (next_node && curr_node->val == next_node->val) {
                ListNode* tmp = next_node->next;
                delete next_node;
                next_node = tmp;
            }

            if (curr_node->next == next_node) {
                prev_node = curr_node;
            } else {
                prev_node->next = next_node;
                delete curr_node;
            }
            curr_node = next_node;
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
    head = sol.deleteDuplicates(head);
    std::cout << head << std::endl;

    ListNode* last;
    while (head) {
        last = head;
        head = head->next;
        delete last;
    }

    return 0;
}
