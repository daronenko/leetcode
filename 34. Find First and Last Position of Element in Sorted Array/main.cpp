#include <vector>
#include <algorithm>


// class Solution {
//  public:
//     std::vector<int> searchRange(std::vector<int>& nums, int target) {
//         int start = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//
//         if (start == nums.size() || nums[start] != target) {
//             return {-1, -1};
//         }
//
//         int end = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
//
//         return {start, end};
//     }
// };


class Solution {
 public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto [start, end] = std::equal_range(nums.begin(), nums.end(), target);

        if (start == end) {
            return {-1, -1};
        }

        return {static_cast<int>(start - nums.begin()),
                static_cast<int>(end - nums.begin() - 1)};
    }
};


// class Solution {
//  public:
//     std::vector<int> searchRange(const std::vector<int>& nums, int target) {
//         int start = binarySearch(nums, target);
//         int end = binarySearch(nums, target + 1) - 1;
//
//         if (start == nums.size() || nums[start] != target) {
//             return {-1, -1};
//         }
//
//         return {start, end};
//     }
//
//  private:
//     int binarySearch(const std::vector<int>& nums, int target) {
//         int left = 0;
//         int right = nums.size();
//         while (left < right) {
//             int middle = (left + right) / 2;
//             if (nums[middle] >= target) {
//                 right = middle;
//             } else {
//                 left = middle + 1;
//             }
//         }
//
//         return left;
//     }
// };


int main() {
    return 0;
}
