#include <iostream>
#include <vector>
#include <string>


class Solution {
 public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> vec;

        int i = 0;
        while (i < path.length()) {
            if (path[i] == '/') {
                ++i;
                continue;
            }

            std::string token;
            while (i < path.length() && path[i] != '/') {
                token += path[i++];
            }

            if (token == ".") {
                continue;
            } else if (token == "..") {
                if (!vec.empty()) {
                    vec.pop_back();
                }
            } else {
                vec.push_back(token);
            }
        }

        std::string result;
        for (const std::string& part : vec) {
            result += '/' + part;
        }

        return !result.empty() ? result : "/";
    }
};


int main() {
    Solution sol;
    {
        std::string path = "/home/";
        std::cout << sol.simplifyPath(path) << std::endl;
    }
    {
        std::string path = "/../";
        std::cout << sol.simplifyPath(path) << std::endl;
    }
    {
        std::string path = "/home//foo/";
        std::cout << sol.simplifyPath(path) << std::endl;
    }
}
