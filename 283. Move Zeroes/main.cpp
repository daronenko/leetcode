#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>


template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vec) {
    for (const int& value: vec) {
        out << value << ' ';
    }
    return out;
}


class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        size_t zero_i = std::find(nums.begin(), nums.end(), 0) - nums.begin();
        for (size_t i = zero_i + 1; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                std::swap(nums[i], nums[zero_i]);
                ++zero_i;
            }
        }
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{0, 1, 0, 3, 12};
        sol.moveZeroes(nums);
        std::cout << nums << std::endl;
    }
    {
        std::vector<int> nums{0};
        sol.moveZeroes(nums);
        std::cout << nums << std::endl;
    }
    return 0;
}
