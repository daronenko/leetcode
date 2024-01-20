#include <iostream>


class Solution {
 public:
    std::uint32_t reverseBits(std::uint32_t n) {
        std::uint32_t answer = 0;

        for (int i = 0; i < 32; ++i) {
            answer = answer * 2 + n % 2;
            n /= 2;
        }

        return answer;
    }
};


// class Solution {
//  public:
//     std::uint32_t reverseBits(std::uint32_t n) {
//         std::uint32_t answer = 0;
//
//         for (int i = 0; i < 32; ++i) {
//             answer <<= 1;
//             answer |= (n & 1);
//             n >>= 1;
//         }
//
//         return answer;
//     }
// };


int main() {
    Solution sol;
    {
        std::uint32_t n = 43261596;
        std::cout << sol.reverseBits(n) << std::endl;
    }
    {
        std::uint32_t n = 4294967293;
        std::cout << sol.reverseBits(n) << std::endl;
    }
    return 0;
}
