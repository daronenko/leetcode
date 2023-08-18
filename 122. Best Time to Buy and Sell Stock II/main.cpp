#include <iostream>
#include <vector>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit += std::max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> prices{7, 1, 5, 3, 6, 4};
        std::cout << sol.maxProfit(prices) << std::endl;
    }
    {
        std::vector<int> prices{1, 2, 3, 4, 5};
        std::cout << sol.maxProfit(prices) << std::endl;
    }
    {
        std::vector<int> prices{7, 6, 4, 3, 1};
        std::cout << sol.maxProfit(prices) << std::endl;
    }
    return 0;
}

