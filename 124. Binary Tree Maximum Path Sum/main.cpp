#include <algorithm>
#include <limits>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution {
 public:
    int maxPathSum(TreeNode* root) {
        int result = std::numeric_limits<int>::min();
        maxSum(root, result);

        return result;
    }

 private:
    int maxSum(TreeNode* root, int& sum) {
        if (!root) {
            return 0;
        }

        int left_branch_sum = root->val + maxSum(root->left, sum);
        int right_branch_sum = root->val + maxSum(root->right, sum);

        sum = std::max({
            sum,
            root->val,
            left_branch_sum,
            right_branch_sum,
            left_branch_sum + right_branch_sum - root->val
        });

        return std::max({
            left_branch_sum,
            right_branch_sum,
            root->val
        });
    }
};


int main() {
    return 0;
}
