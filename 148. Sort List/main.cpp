struct ListNode {
     int val;
     ListNode* next;

     ListNode(): val(0), next(nullptr) {}

     explicit ListNode(int x): val(x), next(nullptr) {}

     ListNode(int x, ListNode* next): val(x), next(next) {}
};


class Solution {
 public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;

        return mergeLists_(sortList(head), sortList(fast));
    }

 private:
    ListNode* mergeLists_(ListNode* head_1, ListNode* head_2) {
        ListNode* current_node = new ListNode();
        ListNode* dummy_node = current_node;

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
