#include <vector>
#include <unordered_map>


class Node {
 public:
    int val;
    std::vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }

    explicit Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
 public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        if (!_old_to_new.contains(node)) {
            _old_to_new[node] = new Node(node->val);
            for (Node* origin_neighbor : node->neighbors) {
                _old_to_new[node]->neighbors.push_back(cloneGraph(origin_neighbor));
            }
        }

        return _old_to_new[node];
    }

 private:
    std::unordered_map<Node*, Node*> _old_to_new;
};


int main() {
    return 0;
}
