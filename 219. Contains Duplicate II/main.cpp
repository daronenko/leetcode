#include <iostream>
#include <vector>
#include <unordered_set>


class Solution {
 public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> window;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            if (right - left > k) {
                window.erase(nums[left++]);
            }

            if (window.contains(nums[right])) {
                return true;
            } else {
                window.insert(nums[right]);
            }
        }

        return false;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{1, 2, 3, 1};
        int k = 3;
        std::cout << std::boolalpha << sol.containsNearbyDuplicate(nums, k) << std::endl;
    }
    {
        std::vector<int> nums{1, 0, 1, 1};
        int k = 1;
        std::cout << std::boolalpha << sol.containsNearbyDuplicate(nums, k) << std::endl;
    }
    {
        std::vector<int> nums{1, 2, 3, 1, 2, 3};
        int k = 2;
        std::cout << std::boolalpha << sol.containsNearbyDuplicate(nums, k) << std::endl;
    }
    return 0;
}
