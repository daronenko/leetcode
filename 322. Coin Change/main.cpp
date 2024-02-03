#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>


class Solution {
 public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<std::int64_t> dp(amount + 1, std::numeric_limits<int>::max());
        dp[0] = 0;

        for (int k = 1; k <= amount; ++k) {
            for (int coin : coins) {
                if (k - coin >= 0) {
                    dp[k] = std::min(dp[k], 1 + dp[k - coin]);
                }
            }
        }

        return dp[amount] != std::numeric_limits<int>::max() ? dp[amount] : -1;
    }
};


int main() {
    return 0;
}
