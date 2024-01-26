#include <string>
#include <queue>
#include <utility>
#include <unordered_set>


class Solution {
 public:
    int ladderLength(
        std::string begin_word,
        std::string end_word,
        std::vector<std::string>& word_list
    ) {
        std::unordered_set<std::string> possible_words(word_list.begin(), word_list.end());

        if (!possible_words.contains(end_word)) {
            return 0;
        }

        std::queue<std::pair<std::string, int>> q;
        q.push({begin_word, 1});

        while (!q.empty()) {
            auto [current_word, transformations_number] = q.front();
            q.pop();

            if (current_word == end_word) {
                return transformations_number;
            }

            for (int i = 0; i < current_word.size(); ++i) {
                auto tmp = current_word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    tmp[i] = c;
                    if (possible_words.contains(tmp)) {
                        q.push({tmp, transformations_number + 1});
                        possible_words.erase(current_word);
                    }
                }
            }
        }

        return 0;
    }
};


int main() {
    return 0;
}
