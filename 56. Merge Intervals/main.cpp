#include <algorithm>
#include <vector>


class Solution {
 public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (result.back()[1] >= intervals[i][0]) {
                result.back()[1] = std::max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
