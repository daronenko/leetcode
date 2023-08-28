#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
 public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (int left = 0; left < nums.size() - 2; ++left) {
            if (left > 0 && nums[left - 1] == nums[left]) {
                continue;
            }

            int middle = left + 1;
            int right = nums.size() - 1;
            while (middle < right) {
                int total = nums[left] + nums[middle] + nums[right];

                if (total < 0) {
                    ++middle;
                } else if (total > 0) {
                    --right;
                } else {
                    result.push_back({nums[left], nums[middle], nums[right]});

                    while (middle + 1 < right && nums[middle] == nums[middle + 1]) {
                        ++middle;
                    }
                    while (middle < right - 1 && nums[right - 1] == nums[right]) {
                        --right;
                    }

                    ++middle;
                    --right;
                }
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
