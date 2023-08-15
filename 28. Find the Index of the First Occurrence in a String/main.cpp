#include <iostream>
#include <string>


class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        size_t j = 0;
        for (size_t i = 0; i < haystack.size(); ++i) {
            for (j = 0; j < needle.size() && i < haystack.size(); ++j) {
                if (haystack[j + i] != needle[j])
                    break;
            }
            if (j == needle.size())
                return i;
        }
        return -1;
    }
};


int main() {
    Solution s;
    {
        std::string haystack = "sadbutsad";
        std::string needle = "sad";
        std::cout << s.strStr(haystack, needle) << std::endl;
    }
    {
        std::string haystack = "leetcode";
        std::string needle = "leeto";
        std::cout << s.strStr(haystack, needle) << std::endl;
    }
    return 0;
}
