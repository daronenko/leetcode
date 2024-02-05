#include <string>
#include <vector>


class Solution {
 public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        std::vector<std::vector<bool>> dp(s1.size() + 1, std::vector<bool>(s2.size() + 1, false));
        dp[s1.size()][s2.size()] = true;

        for (int i = s1.size(); i >= 0; --i) {
            for (int j = s2.size(); j >= 0; --j) {
                if (i < s1.size() && s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                }
                if (j < s2.size() && s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];
    }
};


int main() {
    return 0;
}
