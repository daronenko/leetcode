#include <algorithm>
#include <vector>


class Solution {
 public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                         std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;

        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }

        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            ++i;
        }
        result.push_back(newInterval);

        while (i < intervals.size()) {
            result.push_back(intervals[i++]);
        }

        return result;
    }
};


int main() {
    return 0;
}
