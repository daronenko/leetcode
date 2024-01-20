#include <iostream>
#include <string>
#include <iterator>


class Solution {
 public:
    std::string addBinary(std::string a, std::string b) {
        std::string answer;

        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += a[i--] - '0';
            }
            if (j >= 0) {
                carry += b[j--] - '0';
            }

            answer += carry % 2 + '0';
            carry /= 2;
        }

        std::reverse(std::begin(answer), std::end(answer));
        return answer;
    }
};


int main() {
    Solution sol;
    {
        std::string a{"11"};
        std::string b{"1"};
        std::cout << sol.addBinary(a, b) << std::endl;
    }
    {
        std::string a{"1010"};
        std::string b{"1011"};
        std::cout << sol.addBinary(a, b) << std::endl;
    }
    return 0;
}
