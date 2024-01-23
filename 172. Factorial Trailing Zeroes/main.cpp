#include <algorithm>
#include <iostream>


// class Solution {
//  public:
//     int trailingZeroes(int n) {
//         int result = 0;
//         while (n /= 5) {
//             result += n;
//         }
//
//         return result;
//     }
// };


class Solution {
 public:
    int trailingZeroes(int n) {
        int multiplier = 2;
        int count_2 = 0;
        while (multiplier <= n) {
            count_2 += n / multiplier;
            multiplier *= 2;
        }

        multiplier = 5;
        int count_5 = 0;
        while (multiplier <= n) {
            count_5 += n / multiplier;
            multiplier *= 5;
        }

        return std::min(count_2, count_5);
    }
};


int main() {
    Solution sol;
    {
        int n = 3;
        std::cout << sol.trailingZeroes(n) << std::endl;
    }
    {
        int n = 5;
        std::cout << sol.trailingZeroes(n) << std::endl;
    }
    {
        int n = 0;
        std::cout << sol.trailingZeroes(n) << std::endl;
    }
    return 0;
}
