#include <iostream>
#include <vector>
#include <string>


class Solution {
 public:
    bool isIsomorphic(std::string s, std::string t) {
        std::vector<int> map_1(256, 0), map_2(256, 0);
        for (int i = 0; i < s.size(); ++i) {
            if (map_1[s[i]] != map_2[t[i]]) {
                return false;
            }

            map_1[s[i]] = i + 1;
            map_2[t[i]] = i + 1;
        }

        return true;
    }
};


int main() {
    Solution sol;
    {
        std::string s = "egg";
        std::string t = "add";
        std::cout << std::boolalpha << sol.isIsomorphic(s, t) << std::endl;
    }
    {
        std::string s = "foo";
        std::string t = "bar";
        std::cout << std::boolalpha << sol.isIsomorphic(s, t) << std::endl;
    }
    {
        std::string s = "paper";
        std::string t = "title";
        std::cout << std::boolalpha << sol.isIsomorphic(s, t) << std::endl;
    }
}
