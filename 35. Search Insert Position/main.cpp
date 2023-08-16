#include <iostream>
#include <vector>


class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = -1;
        int right = nums.size();
        int middle;
        while (left < right - 1) {
            middle = (left + right) / 2;
            if (nums[middle] < target) {
                left = middle;
            } else {
                right = middle;
            }
        }
        return right;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{1, 3, 5, 6};
        std::cout << sol.searchInsert(nums, 5) << std::endl;
    }
    {
        std::vector<int> nums{1, 3, 5, 6};
        std::cout << sol.searchInsert(nums, 2) << std::endl;
    }
    {
        std::vector<int> nums{1, 3, 5, 6};
        std::cout << sol.searchInsert(nums, 7) << std::endl;
    }
}
