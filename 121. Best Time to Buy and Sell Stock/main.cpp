#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


std::ostream& operator << (std::ostream& out, const std::vector<int>& vec) {
    for (const int value: vec) {
        out << value << ' ';
    }
    return out;
}


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int start_price  = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            start_price = std::min(start_price, prices[i]);
            max_profit = std::max(max_profit, prices[i] - start_price);
        }
        return max_profit;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> prices{7, 1, 5, 3, 6, 4};
        std::cout << sol.maxProfit(prices) << std::endl;

    }
    {
        std::vector<int> prices{7, 6, 4, 3, 1};
        std::cout << sol.maxProfit(prices) << std::endl;
    }
    return 0;
}

