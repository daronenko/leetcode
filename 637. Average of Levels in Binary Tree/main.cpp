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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> result;

        std::queue<TreeNode*> queue;
        queue.push(root);

        TreeNode* curr_node = root;
        while (!queue.empty()) {
            int64_t level_total = 0;

            int n = queue.size();
            for (int i = 0; i < n; ++i) {
                curr_node = queue.front();
                queue.pop();
                level_total += curr_node->val;

                if (curr_node->left) {
                    queue.push(curr_node->left);
                }

                if (curr_node->right) {
                    queue.push(curr_node->right);
                }
            }

            result.push_back(static_cast<double>(level_total) / n);
        }

        return result;
    }
};


int main() {
    return 0;
}
