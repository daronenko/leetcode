#include <iostream>
#include <string>
#include <unordered_map>


class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> translation{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (translation[s[i]] < translation[s[i + 1]]) {
                result -= translation[s[i]];
            } else {
                result += translation[s[i]];
            }
        }

        return result;
    }
};


int main() {
    Solution sol;
    {
        std::string str = "III";
        std::cout << sol.romanToInt(str) << std::endl;
    }
    {
        std::string str = "LVIII";
        std::cout << sol.romanToInt(str) << std::endl;
    }
    {
        std::string str = "MCMXCIV";
        std::cout << sol.romanToInt(str) << std::endl;
    }
    return 0;
}
