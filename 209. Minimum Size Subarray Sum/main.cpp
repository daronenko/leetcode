#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>


class Solution {
 public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0, right = 0;
        int total = 0;
        int min_len = std::numeric_limits<int>::max();

        while (right < nums.size()) {
            total += nums[right++];
            while (total >= target) {
                min_len = std::min(min_len, right - left);
                total -= nums[left++];
            }
        }

        return min_len == std::numeric_limits<int>::max() ? 0 : min_len;
    }
};


int main() {
    Solution sol;
    {
        int target = 7;
        std::vector<int> nums{2, 3, 1, 2, 4, 3};
        std::cout << sol.minSubArrayLen(target, nums) << std::endl;
    }
    {
        int target = 4;
        std::vector<int> nums{1, 4, 4};
        std::cout << sol.minSubArrayLen(target, nums) << std::endl;
    }
    {
        int target = 11;
        std::vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
        std::cout << sol.minSubArrayLen(target, nums) << std::endl;
    }
}
