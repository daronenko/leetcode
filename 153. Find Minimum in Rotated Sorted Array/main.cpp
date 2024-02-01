#include <limits>
#include <vector>
#include <algorithm>


// class Solution {
//  public:
//     int findMin(std::vector<int>& nums) {
//         return *std::min_element(nums.begin(), nums.end());
//     }
// };


class Solution {
 public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int min = std::numeric_limits<int>::max();

        while (left <= right) {
            int middle = (left + right) / 2;

            if (nums[middle] <= nums[right]) {
                min = std::min(min, nums[middle]);
                right = middle - 1;
            } else if (nums[middle] >= nums[left]) {
                min = std::min(min, nums[left]);
                left = middle + 1;
            }
        }

        return min;
    }
};


int main() {
    return 0;
}
