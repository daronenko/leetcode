#include <vector>
#include <queue>
#include <utility>


class Solution {
 public:
    std::vector<std::vector<int>> kSmallestPairs(
        std::vector<int>& nums_1,
        std::vector<int>& nums_2,
        int k
    ) {
        std::vector<std::vector<int>> result;
        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>
        > min_heap;

        for (int num : nums_1) {
            min_heap.push({num + nums_2[0], 0});
        }

        while (k-- && !min_heap.empty()) {
            auto [sum, idx] = min_heap.top();
            min_heap.pop();

            result.push_back({sum - nums_2[idx], nums_2[idx]});

            if (idx + 1 < nums_2.size()) {
                min_heap.push({sum - nums_2[idx] + nums_2[idx + 1], idx + 1});
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
