#include <vector>


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;

     TreeNode(): val(0), left(nullptr), right(nullptr) {}

     explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

     TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution {
 public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }

        return buildBST_(0, nums.size(), nums);
    }

 private:
    TreeNode* buildBST_(int left, int right, const std::vector<int>& nums) {
        if (left >= right) {
            return nullptr;
        }

        int middle = (left + right) / 2;

        TreeNode* node = new TreeNode(
            nums[middle],
            buildBST_(left, middle, nums),
            buildBST_(middle + 1, right, nums)
        );

        return node;
    }
};


int main() {
    return 0;
}
