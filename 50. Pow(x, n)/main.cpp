#include <iostream>


// class Solution {
//  public:
//     double myPow(double x, int n) {
//         if (x == 0.0 && n < 0) {
//             return 1.0;
//         }
//
//         if (n < 0) {
//             x = 1 / x;
//         }
//
//         n = std::abs(n);
//         double result = 1;
//         while (n) {
//             if (n & 1) {
//                 result *= x;
//             }
//
//             x *= x;
//             n >>= 1;
//         }
//
//         return result;
//     }
// };


class Solution {
 public:
    double myPow(double x, int n) {
        if (x == 0.0 && n < 0) {
            return 1.0;
        }

        if (n < 0) {
            return 1.0 / pow_help_(x, std::abs(n));
        }

        return pow_help_(x, std::abs(n));
    }

 private:
    double pow_help_(double x, long long n) {
        if (x == 0) {
            return 0.0;
        }

        if (n == 0) {
            return 1.0;
        }

        double result = pow_help_(x * x, n / 2);
        if (n % 2) {
            result *= x;
        }

        return result;
    }
};


int main() {
    Solution sol;
    {
        double x = 2.0;
        int n = 10;
        std::cout << sol.myPow(x, n) << std::endl;
    }
    {
        double x = 2.1;
        int n = 3;
        std::cout << sol.myPow(x, n) << std::endl;
    }
    {
        double x = 2.0;
        int n = -2;
        std::cout << sol.myPow(x, n) << std::endl;
    }
    {
        double x = 2.0;
        int n = 0;
        std::cout << sol.myPow(x, n) << std::endl;
    }
    {
        double x = 0.0;
        int n = -2;
        std::cout << sol.myPow(x, n) << std::endl;
    }

    return 0;
}
