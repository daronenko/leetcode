#include <vector>


class Solution {
 public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int middle_1 = (left + right) / 2;
            int middle_2 = middle_1 + 1;
            if (nums[middle_1] < nums[middle_2]) {
                left = middle_2;
            } else {
                right = middle_1;
            }
        }

        return left;
    }
};


int main() {
    return 0;
}
