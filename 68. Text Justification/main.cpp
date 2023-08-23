#include <iostream>
#include <ostream>
#include <string>
#include <vector>


std::ostream& operator << (std::ostream& out, const std::vector<std::string>& vect) {
    for (const std::string& str: vect) {
        out << str << std::endl;
    }
    return out;
}


class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;

        int words_length = 0, words_count = 0;
        int begin = 0, end = 0;
        while (begin < words.size()) {
            if (end < words.size() && words_length + words[end].length() + words_count <= maxWidth) {
                words_length += words[end++].length();
                ++words_count;
            } else {
                if (end - begin == 1 || end == words.size()) {
                    result.push_back(_leftJustify(words, begin, end, maxWidth));
                } else {
                    result.push_back(_centerJustify(words, begin, end, maxWidth, words_length));
                }
                begin = end;
                words_length = words_count = 0;
            }
        }

        return result;
    }

protected:
    std::string _leftJustify(
        const std::vector<std::string>& words,
        const int begin,
        const int end,
        const int maxWidth
    ) {
        std::string result(maxWidth, ' ');

        int i = 0;
        for (int word_index = begin; word_index < end; ++word_index) {
            int j = 0;
            while (j < words[word_index].length()) {
                result[i++] = words[word_index][j++];
            }
            ++i;
        }

        return result;
    }

    std::string _centerJustify(
        const std::vector<std::string>& words,
        const int begin,
        const int end,
        const int maxWidth,
        const int words_length
    ) {
        std::string result(maxWidth, ' ');

        int spaces = (maxWidth - words_length) / (end - begin - 1);
        int extra_spaces = (maxWidth - words_length) % (end - begin - 1);

        int i = 0;
        for (int word_index = begin; word_index < end; ++word_index) {
            int j = 0;
            while (j < words[word_index].length()) {
                result[i++] = words[word_index][j++];
            }
            i += spaces;
            if (extra_spaces) {
                i += 1;
                --extra_spaces;
            }
        }

        return result;
    }
};


int main() {
    Solution sol;
    {
        std::vector<std::string> words{"This", "is", "an", "example", "of", "text", "justification."};
        std::cout << sol.fullJustify(words, 16) << std::endl;
    }
    {
        std::vector<std::string> words{"What", "must", "be", "acknowledgment", "shall", "be"};
        std::cout << sol.fullJustify(words, 16) << std::endl;
    }
    {
        std::vector<std::string> words{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
        std::cout << sol.fullJustify(words, 20) << std::endl;
    }
    return 0;
}
