#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>


class Solution {
 public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> set;
        int max_len = 0;

        int left = 0, right = 0;
        while (right < s.size()) {
            if (set.contains(s[right])) {
                set.erase(s[left++]);
            } else {
                set.insert(s[right++]);
                max_len = std::max(max_len, right - left);
            }
        }

        return max_len;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "abcabcbb";
        std::cout << sol.lengthOfLongestSubstring(s) << std::endl;
    }
    {
        std::string s = "bbbbb";
        std::cout << sol.lengthOfLongestSubstring(s) << std::endl;
    }
    {
        std::string s = "pwwkew";
        std::cout << sol.lengthOfLongestSubstring(s) << std::endl;
    }
}
