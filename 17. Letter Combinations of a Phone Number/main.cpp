#include <vector>
#include <string>


class Solution {
 public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }

        std::vector<std::string> result{""};
        for (auto digit : digits) {
            std::vector<std::string> tmp;
            for (auto candidate : LETTERS_[digit - '0']) {
                for (auto accumulated : result) {
                    tmp.push_back(accumulated + candidate);
                }
            }
            result.swap(tmp);
        }

        return result;
    }

 private:
    const std::vector<std::string> LETTERS_{
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
};


int main() {
    return 0;
}
