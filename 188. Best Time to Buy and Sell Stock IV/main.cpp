#include <algorithm>
#include <vector>


class Solution {
 public:
    int maxProfit(int k, std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        if (k > prices.size()) {
            int result = 0;

            for (int i = 1; i < prices.size(); ++i) {
                int profit = prices[i] - prices[i - 1];
                if (profit > 0) {
                    result += profit;
                }
            }

            return result;
        }

        std::vector<int> dp(prices.size(), 0);
        for (int t = 0; t < k; ++t) {
            int buy = -prices[0];
            int profit = 0;
            for (int i = 1; i < prices.size(); ++i) {
                buy = std::max(buy, dp[i] - prices[i]);
                profit = std::max(profit, buy + prices[i]);
                dp[i] = profit;
            }
        }

        return dp.back();
    }
};


int main() {
    return 0;
}
