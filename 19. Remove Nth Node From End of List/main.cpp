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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;

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
    head = sol.removeNthFromEnd(head, 2);
    std::cout << head << std::endl;

    ListNode* last;
    while (head) {
        last = head;
        head = head->next;
        delete last;
    }

    return 0;
}
