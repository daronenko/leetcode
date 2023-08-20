#include <iostream>
#include <vector>


class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;
        int max_left = height[left];

        int right = height.size() - 1;
        int max_right = height[right];

        int volume = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= max_left) {
                    max_left = height[left];
                } else {
                    volume += max_left - height[left];
                }
                ++left;
            } else {
                if (height[right] >= max_right) {
                    max_right = height[right];
                } else {
                    volume += max_right - height[right];
                }
                --right;
            }
        }

        return volume;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        std::cout << sol.trap(height) << std::endl;
    }
    {
        std::vector<int> height{4, 2, 0, 3, 2, 5};
        std::cout << sol.trap(height) << std::endl;
    }
    return 0;
}

