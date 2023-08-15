#include <iostream>
#include <string>
#include <ios>


class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        if (s == "")
            return false;

        std::string tmp = s + s;
        return tmp.substr(1, tmp.size() - 2).find(s) != std::string::npos;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "abab";
        std::cout << std::boolalpha << sol.repeatedSubstringPattern(s) << std::endl;
    }
    {
        std::string s = "aba";
        std::cout << std::boolalpha << sol.repeatedSubstringPattern(s) << std::endl;
    }
    {
        std::string s = "abcabcabcabc";
        std::cout << std::boolalpha << sol.repeatedSubstringPattern(s) << std::endl;
    }
    return 0;
}

