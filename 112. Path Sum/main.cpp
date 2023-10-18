struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode *right): val(x), left(left), right(right) {}
};


// class Solution {
//  public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if (!root) {
//             return false;
//         }
//
//         if (!root->left && !root->right) {
//             return (root->val == targetSum);
//         }
//
//         bool left = hasPathSum(root->left, targetSum - root->val);
//         bool right = hasPathSum(root->right, targetSum - root->val);
//
//         return left || right;
//     }
// };


class Solution {
 public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return _helper(root, targetSum, 0);
    }

 private:
    bool _helper(TreeNode* root, int targetSum, int currentSum) {
        if (!root) {
            return false;
        }

        if (!root->left && !root->right) {
            currentSum += root->val;
            if (currentSum == targetSum) {
                return true;
            }
        }

        return _helper(root->left, targetSum, currentSum + root->val)
            || _helper(root->right, targetSum, currentSum + root->val);
        
    }
};


int main() {
    return 0;
}
