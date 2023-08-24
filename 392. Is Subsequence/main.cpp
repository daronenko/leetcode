#include <iostream>
#include <string>


class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }

        return (i == s.length()) ? true : false;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "abc";
        std::string t = "ahbgdc";
        std::cout << sol.isSubsequence(s, t) << std::endl;
    }
    {
        std::string s = "axc";
        std::string t = "ahbgdc";
        std::cout << sol.isSubsequence(s, t) << std::endl;
    }
    return 0;
}
