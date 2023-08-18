#include <algorithm>
#include <iostream>
#include <vector>


// dp
// class Solution {
// public:
//     bool canJump(std::vector<int>& nums) {
//         std::vector<bool> jump(nums.size());
//         jump[nums.size() - 1] = true;
//         for (int i = jump.size() - 2; i >= 0; --i) {
//             for (int j = 0; j <= nums[i] && i + j < nums.size(); ++j) {
//                 if (jump[i + j] == true) {
//                     jump[i] = true;
//                     break;
//                 }
//             }
//         }
//
//         return jump[0];
//     }
// };


// greedy
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > reachable) {
                return false;
            }
            reachable = std::max(i + nums[i], reachable);
        }
        return true;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{2, 3, 1, 1, 4};
        std::cout << std::boolalpha << sol.canJump(nums) << std::endl;
    }
    {
        std::vector<int> nums{3, 2, 1, 0, 4};
        std::cout << std::boolalpha << sol.canJump(nums) << std::endl;
    }
    return 0;
}

