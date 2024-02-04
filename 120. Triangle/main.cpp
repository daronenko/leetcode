#include <algorithm>
#include <vector>


class Solution {
 public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        std::vector<int> dp = triangle[triangle.size() - 1];

        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};


int main() {
    return 0;
}
