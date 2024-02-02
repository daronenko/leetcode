#include <vector>
#include <string>
#include <unordered_set>


// class Solution {
//  public:
//     bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
//         std::vector<bool> dp(s.size() + 1, false);
//         dp[0] = true;
//
//         std::unordered_set<std::string> set(wordDict.begin(), wordDict.end());
//         for (int i = 1; i <= s.size(); ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (dp[j] && set.contains(s.substr(j, i - j))) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//
//         return dp[s.size()];
//     }
// };


class Solution {
 public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1;

        for (int i = s.size() - 1; i >= 0; --i) {
            bool ans = false;
            for (int j = 0; j < wordDict.size() && !ans; ++j) {
                if (s.substr(i, wordDict[j].size()) == wordDict[j]) {
                    ans = ans || dp[i + wordDict[j].size()];
                }
            }
            dp[i] = ans;
        }

        return dp[0];
    }
};


int main() {
    return 0;
}
