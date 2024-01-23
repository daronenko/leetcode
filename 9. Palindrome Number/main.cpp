#include <iostream>
#include <ios>


class Solution {
 public:
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        }

        int revered_number = 0;
        while (x > revered_number) {
            revered_number = revered_number * 10 + x % 10;
            x /= 10;
        }

        return (x == revered_number) || (x == revered_number / 10);
    }
};


int main() {
    Solution sol;
    {
        int x = 121;
        std::cout << std::boolalpha << sol.isPalindrome(x) << std::endl;
    }
    {
        int x = -121;
        std::cout << std::boolalpha << sol.isPalindrome(x) << std::endl;
    }
    {
        int x = 10;
        std::cout << std::boolalpha << sol.isPalindrome(x) << std::endl;
    }
    return 0;
}
