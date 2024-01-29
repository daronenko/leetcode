#include <vector>


struct ListNode {
    int val;
    ListNode* next;

    ListNode(): val(0), next(nullptr) {}

    explicit ListNode(int x): val(x), next(nullptr) {}

    ListNode(int x, ListNode* next): val(x), next(next) {}
};


class Solution {
 public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        return mergeKLists_(0, lists.size() - 1, lists);
    }

 private:
    ListNode* mergeKLists_(int left, int right, std::vector<ListNode*>& lists) {
        if (left == right) {
            return lists[left];
        }

        int middle = (left + right) / 2;
        ListNode* left_node = mergeKLists_(left, middle, lists);
        ListNode* right_node = mergeKLists_(middle + 1, right, lists);

        return mergeLists_(left_node, right_node);
    }

    ListNode* mergeLists_(ListNode* head_1, ListNode* head_2) {
        ListNode* dummy_node = new ListNode();
        ListNode* current_node = dummy_node;

        while (head_1 && head_2) {
            if (head_1->val < head_2->val) {
                current_node->next = head_1;
                head_1 = head_1->next;
            } else {
                current_node->next = head_2;
                head_2 = head_2->next;
            }

            current_node = current_node->next;
        }

        if (head_1) {
            current_node->next = head_1;
        }

        if (head_2) {
            current_node->next = head_2;
        }

        return dummy_node->next;
    }
};


int main() {
     return 0;
}
