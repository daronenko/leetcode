#include <vector>


class Solution {
 public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));

        if (obstacleGrid[0][0] != 1) {
            dp[1][1] = 1;
        }

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (obstacleGrid[i - 1][j - 1] != 1) {
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[rows][cols];
    }
};


int main() {
    return 0;
}
