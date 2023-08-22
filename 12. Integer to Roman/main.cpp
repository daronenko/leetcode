#include <iostream>
#include <string>


class Solution {
public:
    std::string intToRoman(int num) {
        std::string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        std::string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        std::string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        std::string M[] = {"", "M", "MM", "MMM"};

        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};


int main() {
    Solution sol;
    {
        int num = 3;
        std::cout << sol.intToRoman(num) << std::endl;
    }
    {
        int num = 58;
        std::cout << sol.intToRoman(num) << std::endl;
    }
    {
        int num = 1994;
        std::cout << sol.intToRoman(num) << std::endl;
    }
    return 0;
}
