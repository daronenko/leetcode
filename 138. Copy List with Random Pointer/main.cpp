class Node {
 public:
    int val;
    Node* next;
    Node* random;

    explicit Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
 public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        // interweave nodes
        Node* current_node = head;
        while (current_node) {
            Node* new_node = new Node(current_node->val);
            new_node->next = current_node->next;
            current_node->next = new_node;
            current_node = new_node->next;
        }

        // connect to random nodes
        current_node = head;
        while (current_node) {
            if (current_node->random) {
                current_node->next->random = current_node->random->next;
            }
            current_node = current_node->next->next;
        }

        // collect copied nodes and return old nodes to original state
        Node* old_head = head;
        Node* new_head = head->next;

        Node* current_old_node = old_head;
        Node* current_new_node = new_head;

        while (current_old_node) {
            current_old_node->next = current_old_node->next->next;
            current_new_node->next = (current_new_node->next ?
                                      current_new_node->next->next : nullptr);
            current_old_node = current_old_node->next;
            current_new_node = current_new_node->next;
        }

        return new_head;
    }
};


int main() {
    return 0;
}
