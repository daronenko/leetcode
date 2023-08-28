#include <iostream>
#include <vector>


class Solution {
 public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        int total;
        while ((total = numbers[left] + numbers[right]) != target) {
            if (total < target) {
                ++left;
            } else {
                --right;
            }
        }

        return {++left, ++right};
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> numbers{2, 7, 11, 15};
        int target = 9;
        auto result = sol.twoSum(numbers, target);
        std::cout << result[0] << ' ' << result[1] << std::endl;
    }
    {
        std::vector<int> numbers{2, 3, 4};
        int target = 6;
        auto result = sol.twoSum(numbers, target);
        std::cout << result[0] << ' ' << result[1] << std::endl;
    }
    {
        std::vector<int> numbers{-1, 0};
        int target = -1;
        auto result = sol.twoSum(numbers, target);
        std::cout << result[0] << ' ' << result[1] << std::endl;
    }
    return 0;
}
