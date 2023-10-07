#include <algorithm>
#include <queue>
#include <stack>
#include <utility>


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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int max_left = maxDepth(root->left);
        int max_right = maxDepth(root->right);

        return std::max(max_left, max_right) + 1;
    }
};


// bfs
// class Solution {
//  public:
//     int maxDepth(TreeNode* root) {
//         if (!root) {
//             return 0;
//         }
//
//         int depth = 0;
//         std::queue<TreeNode*> queue;
//         queue.push(root);
//
//         while (!queue.empty()) {
//             for (int i = 0, n = queue.size(); i < n; ++i) {
//                 TreeNode* node = queue.front();
//                 queue.pop();
//
//                 if (node->left) {
//                     queue.push(node->left);
//                 }
//
//                 if (node->right) {
//                     queue.push(node->right);
//                 }
//             }
//
//             ++depth;
//         }
//
//         return depth;
//     }
// };


// iteratove dfs
// class Solution {
//  public:
//     int maxDepth(TreeNode* root) {
//         if (!root) {
//             return 0;
//         }
//
//         std::stack<std::pair<TreeNode*, int>> stack;
//         stack.push({root, 1});
//
//         int depth = 1;
//         while (!stack.empty()) {
//             auto item = stack.top();
//             stack.pop();
//
//             if (item.first) {
//                 depth = std::max(depth, item.second);
//                 stack.push({item.first->left, item.second + 1});
//                 stack.push({item.first->right, item.second + 1});
//             }
//         }
//
//         return depth;
//     }
// };


int main() {
    return 0;
}
