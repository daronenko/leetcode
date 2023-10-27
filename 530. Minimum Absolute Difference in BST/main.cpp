#include <algorithm>
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
    int min_diff = std::numeric_limits<int>::max();
    TreeNode* prev_node = nullptr;

    int getMinimumDifference(TreeNode* root) {
        if (!root) {
            return min_diff;
        }

        getMinimumDifference(root->left);

        if (prev_node) {
            min_diff = std::min(min_diff, root->val - prev_node->val);
        }
        prev_node = root;

        getMinimumDifference(root->right);

        return min_diff;
    }
};


int main() {
    return 0;
}
