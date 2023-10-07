#include <queue>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


// recursive dfs
class Solution {
 public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        return isMirror(root->left, root->right);
    }

 private:
    bool isMirror(TreeNode* left_node, TreeNode* right_node) {
        if (!left_node && !right_node) {
            return true;
        }

        if (!left_node || !right_node) {
            return false;
        }

        return (left_node->val == right_node->val
                && isMirror(left_node->left, right_node->right)
                && isMirror(left_node->right, right_node->left));
    }
};


// iterative bfs
// class Solution {
//  public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) {
//             return true;
//         }
//
//         std::queue<TreeNode*> queue;
//         queue.push(root);
//         queue.push(root);
//
//         while (!queue.empty()) {
//             TreeNode* left_node = queue.front();
//             queue.pop();
//             TreeNode* right_node = queue.front();
//             queue.pop();
//
//             if (!left_node && !right_node) {
//                 continue;
//             }
//
//             if (!left_node || !right_node || left_node->val != right_node->val) {
//                 return false;
//             }
//
//             queue.push(left_node->left);
//             queue.push(right_node->right);
//
//             queue.push(left_node->right);
//             queue.push(right_node->left);
//         }
//
//         return true;
//     }
// };


int main() {
    return 0;
}
