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
//     TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
//         return _constructNode(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
//     }
//
//  private:
//     TreeNode* _constructNode(int in_left, int in_right, int post_left, int post_right,
//                              std::vector<int>& inorder, std::vector<int>& postorder) {
//         if (in_left > in_right || post_left > post_right) {
//             return nullptr;
//         }
//
//         TreeNode* node = new TreeNode(postorder[post_right]);
//
//         int in_index = 0;
//         for (int i = in_left; i <= in_right; ++i) {
//             if (inorder[i] == node->val) {
//                 in_index = i;
//                 break;
//             }
//         }
//
//         node->left = _constructNode(in_left, in_index - 1, post_left, post_left + (in_index - in_left) - 1,
//                                     inorder, postorder);
//         node->right = _constructNode(in_index + 1, in_right, post_right - (in_right - in_index), post_right - 1,
//                                      inorder, postorder);
//         
//         return node;
//     }
// };


// O(n)
class Solution {
 public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        std::unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }

        return _constructNode(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder, in_map);
    }

 private:
    TreeNode* _constructNode(int in_left, int in_right, int post_left, int post_right,
                             std::vector<int>& inorder, std::vector<int>& postorder, std::unordered_map<int, int>& in_map) {
        if (in_left > in_right || post_left > post_right) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(postorder[post_right]);
        int in_index = in_map[node->val];
        
        node->left = _constructNode(in_left, in_index - 1, post_left, post_left + (in_index - in_left) - 1,
                                    inorder, postorder, in_map);
        node->right = _constructNode(in_index + 1, in_right, post_right - (in_right - in_index), post_right - 1,
                                     inorder, postorder, in_map);
        
        return node;
    }
};


int main() {
    return 0;
}
