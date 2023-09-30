#include <iostream>
#include <unordered_set>


struct ListNode {
    int val;
    ListNode* next;

    explicit ListNode(int x): val(x), next(nullptr) {}
};


class Solution {
 public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};


// class Solution {
//  public:
//     bool hasCycle(ListNode* head) {
//         std::unordered_set<ListNode*> nodes;
//         ListNode* current_node = head;
//
//         while (current_node) {
//             if (nodes.contains(current_node)) {
//                 return true;
//             }
//             nodes.insert(current_node);
//             current_node = current_node->next;
//         }
//
//         return false;
//     }
// };


int main() {
    return 0;
}
