#include <algorithm>
#include <iostream>
#include <string>


class Solution {
public:
    std::string reverseWords(std::string s) {
        std::reverse(s.begin(), s.end());

        int len = s.length();
        int l = 0, r = 0;
        int i = 0;
        while (i < len) {
            while (i < len && s[i] == ' ') {
                ++i;
            }
            while (i < len && s[i] != ' ') {
                s[r++] = s[i++];
            }

            if (l < r) {
                std::reverse(s.begin() + l, s.begin() + r);
                s[r++] = ' ';
                l = r;
            }
        }

        if (r > 0) {
            s.resize(r - 1);
        }

        return s;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "the sky is blue";
        std::cout << sol.reverseWords(s) << std::endl;
    }
    {
        std::string s = "  hello world  ";
        std::cout << sol.reverseWords(s) << std::endl;
    }
    {
        std::string s = "a good   example";
        std::cout << sol.reverseWords(s) << std::endl;
    }
    return 0;
}
