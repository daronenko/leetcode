#include <algorithm>
#include <limits>
#include <vector>

#include <iostream>
#include <ios>


static int fast_io = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution {
 public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int buy_1 = std::numeric_limits<int>::max();
        int profit_1 = std::numeric_limits<int>::min();
        int buy_2 = std::numeric_limits<int>::max();
        int profit_2 = std::numeric_limits<int>::min();

        for (int i = 0; i < prices.size(); ++i) {
            buy_1 = std::min(buy_1, prices[i]);
            profit_1 = std::max(profit_1, prices[i] - buy_1);
            buy_2 = std::min(buy_2, prices[i] - profit_1);
            profit_2 = std::max(profit_2, prices[i] - buy_2);
        }

        return profit_2;
    }
};


int main() {
    return 0;
}
