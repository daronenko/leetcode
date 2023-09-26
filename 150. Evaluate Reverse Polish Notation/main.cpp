#include <functional>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <unordered_map>


class Solution {
 public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (const auto& token : tokens) {
            if (operations.contains(token)) {
                auto operands = _pop_operands(&stack);
                stack.push(operations.at(token)(operands.first, operands.second));
            } else {
                stack.push(std::stoi(token));
            }
        }

        return stack.top();
    }

 private:
    const std::unordered_map<std::string, std::function<int (int, int)>> operations = {
        { "+" , [](int lhs, int rhs) { return lhs + rhs; }},
        { "-" , [](int lhs, int rhs) { return lhs - rhs; }},
        { "*" , [](int lhs, int rhs) { return lhs * rhs; }},
        { "/" , [](int lhs, int rhs) { return lhs / rhs; }}
    };

    std::pair<int, int> _pop_operands(std::stack<int>* stack) {
        int rhs = stack->top();
        stack->pop();

        int lhs = stack->top();
        stack->pop();

        return std::make_pair(lhs, rhs);
    }
};


int main() {
    Solution sol;
    {
        std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
        std::cout << sol.evalRPN(tokens) << std::endl;
    }
    {
        std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
        std::cout << sol.evalRPN(tokens) << std::endl;
    }
    {
        std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        std::cout << sol.evalRPN(tokens) << std::endl;
    }
    return 0;
}
