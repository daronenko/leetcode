#include <iostream>
#include <string>


class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        int ascii_sum = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            ascii_sum += int(s[i]);
            ascii_sum -= int(t[i]);
        }
        ascii_sum -= int(t[t.size() - 1]);

        return char(std::abs(ascii_sum));
    }
};


int main() {
    Solution sol;
    {
        std::string s = "abcd";
        std::string t = "abcde";
        std::cout << sol.findTheDifference(s, t) << std::endl;
    }
    {
        std::string s = "";
        std::string t = "y";
        std::cout << sol.findTheDifference(s, t) << std::endl;
    }
    return 0;
}
