#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>


class Solution {
 public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& word : strs) {
            auto word_copy = word;
            std::sort(word_copy.begin(), word_copy.end());
            groups[word_copy].push_back(word);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& [_, group] : groups) {
            result.push_back(group);
        }

        return result;
    }
};


int main() {
    return 0;
}
