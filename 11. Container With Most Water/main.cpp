#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int max_volume = 0;
        while (left < right) {
            int curr_volume = (right - left) * std::min(height[left], height[right]);
            max_volume = std::max(max_volume, curr_volume);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_volume;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
        std::cout << sol.maxArea(height) << std::endl;
    }
    {
        std::vector<int> height{1, 1};
        std::cout << sol.maxArea(height) << std::endl;
    }
    return 0;
}
