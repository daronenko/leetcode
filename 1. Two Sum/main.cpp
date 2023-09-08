#include <iostream>
#include <unordered_map>
#include <vector>


class Solution {
 public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_i;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];

            if (num_to_i.contains(diff)) {
                return {num_to_i[diff], i};
            } else {
                num_to_i[nums[i]] = i;
            }
        }

        return {};
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{2, 7, 11, 15};
        int target = 9;
        auto result = sol.twoSum(nums, target);
        std::cout << result[0] << ' ' << result[1] << std::endl;
    }
    {
        std::vector<int> nums{3, 2, 4};
        int target = 6;
        auto result = sol.twoSum(nums, target);
        std::cout << result[0] << ' ' << result[1] << std::endl;
    }
    {
        std::vector<int> nums{3, 3};
        int target = 6;
        auto result = sol.twoSum(nums, target);
        std::cout << result[0] << ' ' << result[1] << std::endl;
    }
    return 0;
}
