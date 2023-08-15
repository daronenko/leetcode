#include <iostream>
#include <string>
#include <ios>


class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "anagram";
        std::string t = "nagaram";
        std::cout << std::boolalpha << sol.isAnagram(s, t) << std::endl;
    }
    {
        std::string s = "rat";
        std::string t = "car";
        std::cout << std::boolalpha << sol.isAnagram(s, t) << std::endl;
    }
    return 0;
}
