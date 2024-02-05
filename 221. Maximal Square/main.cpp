#include <algorithm>
#include <vector>


class Solution {
 public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        std::vector<std::vector<int>> dp(
            matrix.size() + 1,
            std::vector<int>(matrix[0].size() + 1, 0)
        );

        int max_side = 0;
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                    max_side = std::max(max_side, dp[i][j]);
                }
            }
        }

        return max_side * max_side;
    }
};


int main() {
    return 0;
}
