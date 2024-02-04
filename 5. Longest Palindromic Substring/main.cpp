#include <string>


class Solution {
 public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2) {
            return s;
        }

        std::string result;
        int result_length = 0;

        for (int i = 0; i < s.size(); ++i) {
            std::string palindrome_odd_length = GetLongestPalindrome_(s, i, i);
            if (palindrome_odd_length.size() > result_length) {
                result = palindrome_odd_length;
                result_length = palindrome_odd_length.size();
            }

            std::string palindrome_even_length = GetLongestPalindrome_(s, i, i + 1);
            if (palindrome_even_length.size() > result_length) {
                result = palindrome_even_length;
                result_length = palindrome_even_length.size();
            }
        }

        return result;
    }

 private:
    std::string GetLongestPalindrome_(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }

        return s.substr(left + 1, right - left - 1);
    }
};


int main() {
    return 0;
}
