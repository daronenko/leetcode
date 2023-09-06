#include <iostream>
#include <limits>
#include <string>
#include <vector>


class Solution {
 public:
    std::string minWindow(std::string s, std::string t) {
        std::vector<int> target(128, 0);
        for (const char letter : t) {
            target[letter]++;
        }

        int need_hits = t.size();

        int min_len = std::numeric_limits<int>::max();
        int head = 0;

        int begin = 0, end = 0;
        while (end < s.size()) {
            if (target[s[end++]]-- > 0) {
                --need_hits;
            }

            while (need_hits == 0) {
                if (end - begin < min_len) {
                    head = begin;
                    min_len = end - head;
                }

                if (target[s[begin++]]++ == 0) {
                    ++need_hits;
                }
            }
        }

        return min_len == std::numeric_limits<int>::max() ? "" : s.substr(head, min_len);
    }
};


int main() {
    Solution sol;
    {
        std::string s = "ADOBECODEBANC";
        std::string t = "ABC";
        std::cout << sol.minWindow(s, t) << std::endl;
    }
    {
        std::string s = "a";
        std::string t = "a";
        std::cout << sol.minWindow(s, t) << std::endl;
    }
    {
        std::string s = "a";
        std::string t = "aa";
        std::cout << sol.minWindow(s, t) << std::endl;
    }
    return 0;
}
