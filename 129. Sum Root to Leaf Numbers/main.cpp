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
    int sumNumbers(TreeNode* root, int number = 0) {
        if (root->left == root->right) {
            return number * 10 + root->val;
        }

        int left_number = 0;
        if (root->left) {
            left_number = sumNumbers(root->left, number * 10 + root->val);
        }

        int right_number = 0;
        if (root->right) {
            right_number = sumNumbers(root->right, number * 10 + root->val);
        }

        return left_number + right_number;
    }
};


int main() {
    return 0;
}
