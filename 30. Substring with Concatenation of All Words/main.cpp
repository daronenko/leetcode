#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


class Solution {
 public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> indexes;

        std::unordered_map<std::string, int> counts;
        for (const auto& word : words) {
            ++counts[word];
        }

        int words_count = words.size();
        int word_len = words[0].length();
        int words_len = word_len * words.size();

        for (int left = 0; left < s.size() - words_len + 1; ++left) {
            std::unordered_map<std::string, int> words_seen;

            int right = 0;
            for (; right < words_count; ++right) {
                std::string curr_word = s.substr(left + right * word_len, word_len);

                ++words_seen[curr_word];                

                if (words_seen[curr_word] > counts[curr_word]) {
                    break;
                }
            }

            if (right == words.size()) {
                indexes.push_back(left);
            }
        }

        return indexes;
    }
};


int main() {
    return 0;
}
