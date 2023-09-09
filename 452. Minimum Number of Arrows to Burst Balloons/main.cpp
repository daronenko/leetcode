#include <algorithm>
#include <vector>
#include <iostream>


class Solution {
 public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end());

        int arrows = 1;
        int last_common_end = points[0][1];
        for (const auto& point : points) {
            if (point[0] > last_common_end) {
                ++arrows;
                last_common_end = point[1];
            }

            last_common_end = std::min(last_common_end, point[1]);
        }

        return arrows;
    }
};


int main() {
    Solution sol;
    {
        std::vector<std::vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
        std::cout << sol.findMinArrowShots(points) << std::endl;
    }
    {
        std::vector<std::vector<int>> points{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
        std::cout << sol.findMinArrowShots(points) << std::endl;
    }
    {
        std::vector<std::vector<int>> points{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
        std::cout << sol.findMinArrowShots(points) << std::endl;
    }
    return 0;
}
