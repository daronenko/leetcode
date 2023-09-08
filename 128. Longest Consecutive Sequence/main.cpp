#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>


class Solution {
 public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());

        int max_len = 0;
        for (const int num : nums) {
            if (!set.contains(num - 1)) {
                int curr_len = 1;
                int curr_num = num;
                while (set.contains(curr_num + 1)) {
                    ++curr_len;
                    ++curr_num;
                }

                max_len = std::max(max_len, curr_len);
            }
        }

        return max_len;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{100, 4, 200, 1, 3, 2};
        std::cout << sol.longestConsecutive(nums) << std::endl;
    }
    {
        std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        std::cout << sol.longestConsecutive(nums) << std::endl;
    }
}
