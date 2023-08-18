#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
        sol.rotate(nums, 3);
        std::vector<int> expected{5, 6, 7, 1, 2, 3, 4};
        assert(expected == nums);
    }
    {
        std::vector<int> nums{-1, -100, 3, 99};
        sol.rotate(nums, 2);
        std::vector<int> expected{3, 99, -1, -100};
        assert(expected == nums);
    }
    return 0;
}

