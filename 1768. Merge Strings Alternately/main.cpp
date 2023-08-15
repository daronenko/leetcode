#include <iostream>
#include <string>


class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string result;
        result.resize(word1.size() + word2.size());
        
        size_t result_index = 0;
        size_t word_index = 0;
        while (word_index < std::max(word1.size(), word2.size())) {
            if (word_index < word1.size()) {
                result[result_index] = word1[word_index];
                ++result_index;
            }
            if (word_index < word2.size()) {
                result[result_index] = word2[word_index];
                ++result_index;
            }
            ++word_index;
        }

        return result;
    }
};


int main() {
    Solution s;
    {
        std::string w1 = "abc";
        std::string w2 = "pqr";
        std::cout << s.mergeAlternately(w1, w2) << std::endl;
    }
    {
        std::string w1 = "ab";
        std::string w2 = "pqrs";
        std::cout << s.mergeAlternately(w1, w2) << std::endl;
    }
    {
        std::string w1 = "abcd";
        std::string w2 = "pq";
        std::cout << s.mergeAlternately(w1, w2) << std::endl;
    }
    return 0;
}

