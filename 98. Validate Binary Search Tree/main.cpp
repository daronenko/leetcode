#include <limits>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution {
 public:
    bool isValidBST(TreeNode* root) {
        return _dfs(root, nullptr, nullptr);
    }

 private:
    bool _dfs(TreeNode* node, TreeNode* min_node, TreeNode* max_node) {
        if (!node) {
            return true;
        }

        if (min_node && node->val <= min_node->val) {
            return false;
        }

        if (max_node && node->val >= max_node->val) {
            return false;
        }

        return _dfs(node->left, min_node, node)
            && _dfs(node->right, node, max_node);
    }
};


int main() {
    return 0;
}
