#include <iostream>
#include <string>


class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int word_len = 0;
        int i = s.length() - 1;
        while (s[i] == ' ') {
            --i;
        }
        while (i >= 0 && s[i] != ' ') {
            ++word_len;
            --i;
        }
        return word_len;
    }
};


int main() {
    Solution sol;
    {
        std::string str = "Hello World";
        std::cout << sol.lengthOfLastWord(str) << std::endl;
    }
    {
        std::string str = "   fly me   to   the moon  ";
        std::cout << sol.lengthOfLastWord(str) << std::endl;
    }
    {
        std::string str = "luffy is still joyboy";
        std::cout << sol.lengthOfLastWord(str) << std::endl;
    }
    return 0;
}
