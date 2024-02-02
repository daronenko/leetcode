#include <algorithm>
#include <vector>


class Solution {
 public:
    int rob(std::vector<int>& nums) {
        int prev_profit = 0;
        int curr_profit = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = std::max(prev_profit + nums[i], curr_profit);
            prev_profit = curr_profit;
            curr_profit = tmp;
        }

        return curr_profit;
    }
};


int main() {
    return 0;
}
