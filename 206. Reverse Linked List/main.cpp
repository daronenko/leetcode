#include <iostream>


struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(): val(0), next(nullptr) {}
    
    ListNode(int x): val(x), next(nullptr) {}
    
    ListNode(int x, ListNode* next): val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next_node;
        ListNode* new_list = nullptr;
        
        ListNode* curr_node = head;
        while (curr_node) {
            next_node = curr_node->next;
            curr_node->next = new_list;
            new_list = curr_node;
            curr_node = next_node;
        }

        return new_list;
    }
};


int main() {

    return 0;
}
