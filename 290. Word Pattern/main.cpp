#include <iostream>
#include <unordered_map>
#include <sstream>


class Solution {
 public:
    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<char, int> char_to_int;
        std::unordered_map<std::string, int> str_to_int;
        std::istringstream in(s);

        int i = 0;
        for (std::string curr_word; in >> curr_word; ++i) {
            if (i == pattern.size()
                    || char_to_int[pattern[i]] != str_to_int[curr_word]) {
                return false;
            }

            char_to_int[pattern[i]] = i + 1;
            str_to_int[curr_word] = i + 1;
        }

        return i == pattern.size();
    }
};


int main() {
    Solution sol;
    {
        std::string pattern = "abba";
        std::string s = "dog cat cat dog";
        std::cout << std::boolalpha << sol.wordPattern(pattern, s) << std::endl;
    }
    {
        std::string pattern = "abba";
        std::string s = "dog cat cat fish";
        std::cout << std::boolalpha << sol.wordPattern(pattern, s) << std::endl;
    }
    {
        std::string pattern = "aaaa";
        std::string s = "dog cat cat dog";
        std::cout << std::boolalpha << sol.wordPattern(pattern, s) << std::endl;
    }
    return 0;
}
