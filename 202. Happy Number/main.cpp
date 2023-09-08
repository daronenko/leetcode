#include <iostream>


class Solution {
 public:
    int getSum(int n) {
        int result = 0;
        while (n) {
            int digit = n % 10;
            result += digit * digit;
            n /= 10;
        }

        return result;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);

            if (fast == 1) {
                return true;
            }
        } while (slow != fast);

        return false;
    }
};


int main() {
    Solution sol;
    {
        int n = 19;
        std::cout << std::boolalpha << sol.isHappy(n) << std::endl;
    }
    {
        int n = 2;
        std::cout << std::boolalpha << sol.isHappy(n) << std::endl;
    }
    return 0;
}
