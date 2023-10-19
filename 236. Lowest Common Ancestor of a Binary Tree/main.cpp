struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


class Solution {
 public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }

        auto left_ancestor = lowestCommonAncestor(root->left, p, q);
        auto right_ancestor = lowestCommonAncestor(root->right, p, q);


        if (!left_ancestor) {
            return right_ancestor;
        }

        if (!right_ancestor) {
            return left_ancestor;
        }

        return root;
    }
};


int main() {
    return 0;
}
