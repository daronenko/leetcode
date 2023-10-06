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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0);
        ListNode* left_cursor = &left;
        ListNode right(0);
        ListNode* right_cursor = &right;

        while (head) {
            if (head->val < x) {
                left_cursor->next = head;
                left_cursor = head;
            } else {
                right_cursor->next = head;
                right_cursor = head;
            }

            head = head->next;
        }

        left_cursor->next = right.next;
        right_cursor->next = nullptr;

        return left.next;
    }
};


int main() {
    std::vector<int> nums{1, 4, 3, 2, 5, 2};
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (const int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    ListNode* head = dummy.next;

    Solution sol;
    head = sol.partition(head, 3);
    std::cout << head << std::endl;

    ListNode* last;
    while (head) {
        last = head;
        head = head->next;
        delete last;
    }

    return 0;
}
