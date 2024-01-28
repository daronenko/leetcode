#include <algorithm>
#include <vector>


class Solution {
 public:
    std::vector<std::vector<int>> combinationSum(
        std::vector<int>& candidates,
        int target
    ) {
        std::vector<std::vector<int>> combinations;
        std::vector<int> combination;
        combinationSum_(candidates, target, combinations, combination);

        return combinations;
    }

 private:
    void combinationSum_(
        std::vector<int>& candidates,
        int target,
        std::vector<std::vector<int>>& combinations,
        std::vector<int>& combination,
        int start = 0
    ) {
        if (!target) {
            combinations.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            combination.push_back(candidates[i]);
            combinationSum_(candidates, target - candidates[i],
                            combinations, combination, i);
            combination.pop_back();
        }
    }
};


int main() {
    return 0;
}
