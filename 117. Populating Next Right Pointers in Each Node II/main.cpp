#include <queue>


class Node {
 public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val): val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// class Solution {
//  public:
//     Node* connect(Node* root) {
//         if (!root) {
//             return nullptr;
//         }
//
//         std::queue<Node*> queue;
//         queue.push(root);
//         queue.push(nullptr);
//
//         while (queue.size() > 1) {
//             Node* node = queue.front();
//             queue.pop();
//
//             if (!node) {
//                 queue.push(nullptr);
//                 continue;
//             }
//
//             node->next = queue.front();
//             if (node->left) {
//                 queue.push(node->left);
//             }
//
//             if (node->right) {
//                 queue.push(node->right);
//             }
//         }
//
//         return root;
//     }
// };


class Solution {
 public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node* level_start = root;
        while (level_start) {
            Node* curr_node = level_start;
            Node* dummy = new Node(0);
            Node* prev_node = dummy;

            while (curr_node) {
                if (curr_node->left) {
                    prev_node->next = curr_node->left;
                    prev_node = prev_node->next;
                }

                if (curr_node->right) {
                    prev_node->next = curr_node->right;
                    prev_node = prev_node->next;
                }

                curr_node = curr_node->next;
            }

            level_start = dummy->next;
            delete dummy;
        }

        return root;
    }
};


int main() {
    return 0;
}
