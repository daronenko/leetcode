#include <iostream>
#include <string>
#include <stack>


class Solution {
 public:
    int calculate(std::string s) {
        std::stack<int> signs;
        signs.push(1);

        int64_t number = 0;
        int sign = 1;
        int result = 0;

        for (const char ch : s) {
            if (std::isdigit(ch)) {
                number = number * 10 + ch - '0';
            } else if (ch == '+' || ch == '-') {
                result += signs.top() * sign * number;
                number = 0;
                sign = (ch == '+' ? 1 : -1);
            } else if (ch == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (ch == ')') {
                result += signs.top() * sign * number;
                number = 0;
                signs.pop();
                sign = 1;
            }
        }

        if (number) {
            result += signs.top() * sign * number;
        }

        return result;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "1 + 1";
        std::cout << sol.calculate(s) << std::endl;
    }
    {
        std::string s = " 2-1 + 2 ";
        std::cout << sol.calculate(s) << std::endl;
    }
    {
        std::string s = "(1+(4+5+2)-3)+(6+8)";
        std::cout << sol.calculate(s) << std::endl;
    }
    return 0;
}
