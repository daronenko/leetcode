#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int len = ratings.size();

        int i = 1;
        int total_candies = len;
        while (i < len) {
            if (ratings[i] == ratings[i - 1]) {
                ++i;
                continue;
            }

            int peak = 0;
            for (; i < len && ratings[i] > ratings[i - 1]; ++i) {
                total_candies += ++peak;
            }

            int valley = 0;
            for (; i < len && ratings[i] < ratings[i - 1]; ++i) {
                total_candies += ++valley;
            }

            total_candies -= std::min(peak, valley);
        }

        return total_candies;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> ratings{1, 0, 2};
        std::cout << sol.candy(ratings) << std::endl;
    }
    {
        std::vector<int> ratings{1, 2, 2};
        std::cout << sol.candy(ratings) << std::endl;
    }
    return 0;
}

