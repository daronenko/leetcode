#include <limits>
#include <vector>


class Solution {
 public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = (left + right) / 2;

            double value;
            if ((nums[middle] < nums[0]) == (target < nums[0])) {
                value = nums[middle];
            } else if (target < nums[0]) {
                value = std::numeric_limits<double>::lowest();
            } else {
                value = std::numeric_limits<double>::max();
            }

            if (value < target) {
                left = middle + 1;
            } else if (value > target) {
                right = middle;
            } else {
                return middle;
            }
        }

        return -1;
    }
};


int main() {
    return 0;
}
