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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        return (p->val == q->val
                && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right));
    }
};


// iterative dfs
// class Solution {
//  public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         std::stack<std::pair<TreeNode*, TreeNode*>> stack;
//         stack.push({p, q});
//
//         while (!stack.empty()) {
//             auto [node_p, node_q] = stack.top();
//             stack.pop();
//
//             if (!node_p && !node_q) {
//                 continue;
//             }
//
//             if (!node_p || !node_q || node_p->val != node_q->val) {
//                 return false;
//             }
//
//             stack.push({node_p->left, node_q->left});
//             stack.push({node_p->right, node_q->right});
//         }
//
//         return true;
//     }
// };



int main() {
    return 0;
}
