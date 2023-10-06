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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        int nodes_count = 1;
        ListNode* curr_node = head;
        while (curr_node->next) {
            ++nodes_count;
            curr_node = curr_node->next;
        }
        curr_node->next = head;

        int head_index = nodes_count - k % nodes_count;
        for (int i = 0; i < head_index; ++i) {
            curr_node = curr_node->next;
        }

        head = curr_node->next;
        curr_node->next = nullptr;

        return head;
    }
};


int main() {
    std::vector<int> nums{1, 2};
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (const int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    ListNode* head = dummy.next;

    Solution sol;
    head = sol.rotateRight(head, 0);
    std::cout << head << std::endl;

    ListNode* last;
    while (head) {
        last = head;
        head = head->next;
        delete last;
    }

    return 0;
}
