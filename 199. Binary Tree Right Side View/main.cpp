#include <vector>
#include <queue>


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
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;

        if (!root) {
            return {};
        }

        std::queue<TreeNode*> queue;
        queue.push(root);

        TreeNode* curr_node = root;
        while (!queue.empty()) {
            for (int i = 0, n = queue.size(); i < n; ++i) {
                curr_node = queue.front();
                queue.pop();

                if (curr_node->left) {
                    queue.push(curr_node->left);
                }

                if (curr_node->right) {
                    queue.push(curr_node->right);
                }
            }

            result.push_back(curr_node->val);
        }

        return result;
    }
};


int main() {
    return 0;
}
