#include <algorithm>
#include <limits>
#include <vector>


class Solution {
 public:
    double findMedianSortedArrays(std::vector<int>& nums_1, std::vector<int>& nums_2) {
        int n_1 = nums_1.size();
        int n_2 = nums_2.size();

        if (n_1 > n_2) {
            return findMedianSortedArrays(nums_2, nums_1);
        }

        int total = n_1 + n_2;

        int low = 0;
        int high = n_1;

        double result = 0.0;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = (total + 1) / 2 - i;

            int left_1 = (i > 0) ? nums_1[i - 1] : std::numeric_limits<int>::min();
            int right_1 = (i < n_1) ? nums_1[i] : std::numeric_limits<int>::max();
            int left_2 = (j > 0) ? nums_2[j - 1] : std::numeric_limits<int>::min();
            int right_2 = (j < n_2) ? nums_2[j] : std::numeric_limits<int>::max();

            if (left_1 <= right_2 && left_2 <= right_1) {
                if (total % 2) {
                    result = std::max(left_1, left_2);
                } else {
                    result = (std::max(left_1, left_2) + std::min(right_1, right_2)) / 2.0;
                }
                break;
            } else if (left_1 > right_2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
