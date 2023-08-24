#include <iostream>
#include <string>


class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left <= right) {
            if (!std::isalnum(s[left])) {
                ++left;
            } else if (!std::isalnum(s[right])) {
                --right;
            } else {
                if (std::tolower(s[left]) != std::tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "A man, a plan, a canal: Panama";
        std::cout << sol.isPalindrome(s) << std::endl;
    }
    {
        std::string s = "race a car";
        std::cout << sol.isPalindrome(s) << std::endl;
    }
    {
        std::string s = " ";
        std::cout << sol.isPalindrome(s) << std::endl;
    }
    return 0;
}
