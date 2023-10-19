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
    int countNodes(TreeNode* root) {
        int nodes_count = 0;
        int left_height = _left_height(root);

        while (root) {
            if (_left_height(root->right) == left_height - 1) {
                nodes_count += 1 << left_height;
                root = root->right;
            } else {
                nodes_count += 1 << (left_height - 1);
                root = root->left;
            }

            --left_height;
        }

        return nodes_count;
    }

 private:
    int _left_height(TreeNode* root) {
        return (root ? 1 + _left_height(root->left) : -1);
    }
};


int main() {
    return 0;
}
