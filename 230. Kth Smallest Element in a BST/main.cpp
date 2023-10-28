#include <stack>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


// class Solution {
//  public:
//     int kthSmallest(TreeNode* root, int k) {
//         std::stack<TreeNode*> stack;
//
//         while (root) {
//             stack.push(root);
//             root = root->left;
//         }
//
//         int count = 0;
//         while (count != k) {
//             TreeNode* curr_node = stack.top();
//             stack.pop();
//             ++count;
//
//             if (count == k) {
//                 return curr_node->val;
//             }
//
//             curr_node = curr_node->right;
//             while (curr_node) {
//                 stack.push(curr_node);
//                 curr_node = curr_node->left;
//             }
//         }
//
//         return -1;
//     }
// };


class Solution {
 public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return _result;
    }

 private:
    int _result = -1;

    void dfs(TreeNode* node, int& k) {
        if (!node) {
            return;
        }

        dfs(node->left, k);
        --k;

        if (!k) {
            _result = node->val;
        }

        dfs(node->right, k);
    }
};


int main() {
    return 0;
}
