#include <stack>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class BSTIterator {
 public:
    explicit BSTIterator(TreeNode* root) {
        _prep_left_nodes(root);
    }

    int next() {
        auto node = _stack.top();
        _stack.pop();

        if (node->right) {
            _prep_left_nodes(node->right);
        }

        return node->val;
    }

    bool hasNext() {
        return !_stack.empty();
    }

 private:
    std::stack<TreeNode*> _stack;

    void _prep_left_nodes(TreeNode* root) {
        auto curr_node = root;
        while (curr_node) {
            _stack.push(curr_node);
            curr_node = curr_node->left;
        }
    }
};


int main() {
    return 0;
}
