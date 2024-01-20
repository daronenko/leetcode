#include <iostream>


class Solution {
 public:
    int hammingWeight(std::uint32_t n) {
        int count = 0;

        while (n) {
            count += n % 2;
            n >>= 1;
        }

        return count;
    }
};


int main() {
    Solution sol;
    {
        std::uint32_t n = 11;
        std::cout << sol.hammingWeight(n) << std::endl;
    }
    {
        std::uint32_t n = 128;
        std::cout << sol.hammingWeight(n) << std::endl;
    }
    {
        std::uint32_t n = 4294967293;
        std::cout << sol.hammingWeight(n) << std::endl;
    }
    return 0;
}
