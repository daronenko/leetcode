#include <iostream>
#include <limits>


struct ListNode {
    int val;
    ListNode* next;

    ListNode(): val(0), next(nullptr) {}

    explicit ListNode(int x): val(x), next(nullptr) {}

    ListNode(int x, ListNode* next): val(x), next(next) {}
};


class Solution {
 public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }

        if (!list2) {
            return list1;
        }

        ListNode* head;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* tail = head;
        while (list1 || list2) {
            int val1 = (list1 ? list1->val : std::numeric_limits<int>::max());
            int val2 = (list2 ? list2->val : std::numeric_limits<int>::max());
            if (val1 < val2) {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }

        return head;
    }
};


int main() {
    return 0;
}
