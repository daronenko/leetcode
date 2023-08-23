#include <iostream>
#include <string>


class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        std::string result;
        int increment = (numRows - 1) * 2;
        for (int row = 0; row < numRows; ++row) {
            for (int i = row; i < s.length(); i += increment) {
                result += s[i];
                if (row > 0 && row < numRows - 1 && i + increment - 2 * row < s.length()) {
                    result += s[i + increment - 2 * row];
                }
            }
        }
        
        return result;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "PAYPALISHIRING";
        int numRows = 3;
        std::cout << sol.convert(s, numRows) << std::endl;
    }
    {
        std::string s = "PAYPALISHIRING";
        int numRows = 4;
        std::cout << sol.convert(s, numRows) << std::endl;
    }
    {
        std::string s = "A";
        int numRows = 1;
        std::cout << sol.convert(s, numRows) << std::endl;
    }
    return 0;
}
