#include <vector>
#include <unordered_map>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


// O(n^2) (~O(n))
// class Solution {
//  public:
//     TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
//         return _constructNode(0, 0, inorder.size() - 1, preorder, inorder);
//     }
//
//  private:
//     TreeNode* _constructNode(int pre_left, int in_left, int in_right,
//                          std::vector<int>& preorder, std::vector<int>& inorder) {
//         if (pre_left > preorder.size() - 1 || in_left > in_right) {
//             return nullptr;
//         }
//
//         TreeNode* node = new TreeNode(preorder[pre_left]);
//         int in_index;
//         for (int i = in_left; i <= in_right; ++i) {
//             if (inorder[i] == node->val) {
//                 in_index = i;
//                 break;
//             }
//         }
//
//         node->left = _constructNode(pre_left + 1, in_left, in_index - 1,
//                                 preorder, inorder);
//         // Because `in_index - in_left` represent the number of elements on the left side
//         // of `in_index` which comes earlier than `node->right`, we must skip them in `preorder`
//         // to begin the recursion on right.
//         node->right = _constructNode(pre_left + in_index - in_left + 1, in_index + 1, in_right,
//                                  preorder, inorder);
//
//         return node;
//     }
// };


// O(n)
class Solution {
 public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }

        return _constructNode(0, 0, inorder.size() - 1, preorder, inorder, in_map);
    }

 private:
    TreeNode* _constructNode(int pre_left, int in_left, int in_right, std::vector<int>& preorder,
                             std::vector<int>& inorder, std::unordered_map<int, int>& in_map) {
        if (pre_left > preorder.size() - 1 || in_left > in_right) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[pre_left]);
        int in_index = in_map[node->val];

        node->left = _constructNode(pre_left + 1, in_left, in_index - 1,
                                    preorder, inorder, in_map);
        // Because `in_index - in_left` represent the number of elements on the left side
        // of `in_index` which comes earlier than `node->right`, we must skip them in `preorder`
        // to begin the recursion on right.
        node->right = _constructNode(pre_left + in_index - in_left + 1, in_index + 1, in_right,
                                     preorder, inorder, in_map);

        return node;
    }
};


int main() {
    return 0;
}
