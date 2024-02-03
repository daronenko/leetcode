#include <algorithm>
#include <vector>


// class Solution {
//  public:
//     int lengthOfLIS(std::vector<int>& nums) {
//         std::vector<int> dp(nums.size(), 1);
//         
//         for (int i = nums.size() - 1; i >= 0; --i) {
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 if (nums[i] < nums[j]) {
//                     dp[i] = std::max(dp[i], 1 + dp[j]);
//                 }
//             }
//         }
//
//         return *std::max_element(dp.begin(), dp.end());
//     }
// };


class Solution {
 public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::vector<int> lis;
        for (auto num : nums) {
            auto it = std::lower_bound(lis.begin(), lis.end(), num);

            if (it == lis.end()) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }

        return lis.size();
    }
};


int main() {
    return 0;
}
