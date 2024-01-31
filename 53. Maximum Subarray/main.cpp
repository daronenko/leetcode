#include <algorithm>
#include <limits>
#include <vector>


class Solution {
 public:
    int maxSubArray(std::vector<int>& nums) {
        int max_value = std::numeric_limits<int>::min();
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            max_value = std::max(max_value, sum);
            if (sum < 0) {
                sum = 0;
            }
        }

        return max_value;
    }
};


int main() {
    return 0;
}
