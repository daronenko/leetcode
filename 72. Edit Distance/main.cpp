#include <algorithm>
#include <limits>
#include <string>
#include <vector>


class Solution_1 {
 public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> dp(
            word1.size() + 1,
            std::vector<int>(word2.size() + 1, std::numeric_limits<int>::max())
        );

        for (int i = 0; i <= word1.size(); ++i) {
            dp[i][word2.size()] = word1.size() - i;
        }

        for (int j = 0; j <= word2.size(); ++j) {
            dp[word1.size()][j] = word2.size() - j;
        }

        for (int i = word1.size() - 1; i >= 0; --i) {
            for (int j = word2.size() - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + std::min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
                }
            }
        }

        return dp[0][0];
    }
};


class Solution_2 {
 public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> dp(
            word1.size() + 1,
            std::vector<int>(word2.size() + 1, 0)
        );

        for (int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }

        return dp.back().back();
    }
};


int main() {
    return 0;
}
