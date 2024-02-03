#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>


class Solution {
 public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        if (points.size() <= 2) {
            return points.size();
        }

        int result = 0;
        for (auto it_1 : points) {
            double x_1 = it_1[0];
            double y_1 = it_1[1];

            std::unordered_map<double, int> slopes;
            for (auto it_2 : points) {
                if (it_1 == it_2) {
                    continue;
                }

                double x_2 = it_2[0];
                double y_2 = it_2[1];

                double slope;
                if (x_2 - x_1 == 0) {
                    slope = std::numeric_limits<int>::max();
                } else {
                    slope = (y_2 - y_1) / (x_2 - x_1);
                }

                ++slopes[slope];
                result = std::max(result, slopes[slope]);
            }
        }

        return result + 1;
    }
};


int main() {
    return 0;
}
