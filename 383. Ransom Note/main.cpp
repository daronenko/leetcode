#include <string>
#include <iostream>
#include <vector>


class Solution {
 public:
    bool canConstruct(std::string ransomnote, std::string magazine) {
        std::vector<int> target(26, 0);
        for (const auto letter : magazine) {
            ++target[letter - 'a'];
        }

        for (const auto letter : ransomnote) {
            if (target[letter - 'a']-- <= 0) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution sol;
    {
        std::string ransomNote = "a";
        std::string magazine = "b";
        std::cout << std::boolalpha << sol.canConstruct(ransomNote, magazine) << std::endl;
    }
    {
        std::string ransomNote = "aa";
        std::string magazine = "ab";
        std::cout << std::boolalpha << sol.canConstruct(ransomNote, magazine) << std::endl;
    }
    {
        std::string ransomNote = "aa";
        std::string magazine = "aab";
        std::cout << std::boolalpha << sol.canConstruct(ransomNote, magazine) << std::endl;
    }
}
