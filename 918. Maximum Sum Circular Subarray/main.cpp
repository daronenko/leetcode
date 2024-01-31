#include <vector>


class Solution {
 public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int max_sum = nums[0];
        int cur_max = 0;

        int min_sum = nums[0];
        int cur_min = 0;

        int total = 0;
        for (const auto num : nums) {
            cur_max = std::max(cur_max + num, num);
            max_sum = std::max(max_sum, cur_max);
            cur_min = std::min(cur_min + num, num);
            min_sum = std::min(min_sum, cur_min);
            total += num;
        }

        return (max_sum > 0) ? std::max(max_sum, total - min_sum) : max_sum;
    }
};


int main() {
    return 0;
}
