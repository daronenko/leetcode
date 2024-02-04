#include <vector>


class Solution {
 public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        std::vector<int> dp(grid[0].size(), grid[0][0]);

        for (int i = 1; i < grid[0].size(); ++i) {
            dp[i] = dp[i - 1] + grid[0][i];
        }

        for (int i = 1; i < grid.size(); ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < grid[0].size(); ++j) {
                dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }

        return dp.back();
    }
};


int main() {
    return 0;
}
