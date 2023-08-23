#include <iostream>
#include <vector>
#include <string>


class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::sort(strs.begin(), strs.end());
        std::string commom_prefix;

        int word_1 = 0;
        int word_2 = strs.size() - 1;
        for (int i = 0; strs[word_1][i] && strs[word_2][i]; ++i) {
            if (strs[word_1][i] != strs[word_2][i]) {
                break;
            }
            commom_prefix += strs[word_1][i];
        }

        return commom_prefix;
    }
};


int main() {
    Solution sol;
    {
        std::vector<std::string> strs{"flower", "flow", "flight"};
        std::cout << sol.longestCommonPrefix(strs) << std::endl;
    }
    {
        std::vector<std::string> strs{"dog", "racecar", "car"};
        std::cout << sol.longestCommonPrefix(strs) << std::endl;
    }
    return 0;
}
