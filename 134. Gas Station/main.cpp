#include <cassert>
#include <iostream>
#include <vector>


class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total = 0, current = 0;
        int start = 0;
        int len = gas.size();

        for (int i = 0; i < len; ++i) {
            total += gas[i] - cost[i];
            current += gas[i] - cost[i];

            if (current < 0) {
                current = 0;
                start = i + 1;
            }
        }

        return (total >= 0) ? start : -1;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> gas{1, 2, 3, 4, 5};
        std::vector<int> cost{3, 4, 5, 1, 2};
        std::cout << sol.canCompleteCircuit(gas, cost) << std::endl;

    }
    {
        std::vector<int> gas{2, 3, 4};
        std::vector<int> cost{3, 4, 3};
        std::cout << sol.canCompleteCircuit(gas, cost) << std::endl;
    }
    return 0;
}

