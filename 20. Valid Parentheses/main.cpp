#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>


class Solution {
 public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (const char bracket : s) {
            if (bracket == '(' || bracket == '[' || bracket == '{') {
                stack.push(bracket);
            } else if (!stack.empty() && _brackets.at(stack.top()) == bracket) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();
    }

 private:
    const std::unordered_map<char, char> _brackets = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
};


int main() {
    Solution sol;
    {
        std::string s = "()";
        std::cout << sol.isValid(s) << std::endl;
    }
    {
        std::string s = "()[]{}";
        std::cout << sol.isValid(s) << std::endl;
    }
    {
        std::string s = "(]";
        std::cout << sol.isValid(s) << std::endl;
    }
    {
        std::string s = "(";
        std::cout << sol.isValid(s) << std::endl;
    }
    return 0;
}
