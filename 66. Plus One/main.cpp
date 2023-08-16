#include <iostream>
#include <vector>


template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vec) {
    for (const int& value: vec) {
        out << value << ' ';
    }
    return out;
}


class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            } else {
                digits[i] = 0;
            }
        }

        digits.push_back(0);
        digits[0] = 1;
        
        return digits;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> digits{1, 2, 3};
        std::cout << sol.plusOne(digits) << std::endl;
    }
    {
        std::vector<int> digits{4, 3, 2, 1};
        std::cout << sol.plusOne(digits) << std::endl;
    }
    {
        std::vector<int> digits{9};
        std::cout << sol.plusOne(digits) << std::endl;
    }
    return 0;
}
