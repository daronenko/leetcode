#include <vector>
#include <string>


class Solution {
 public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (search_(i, j, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }

 private:
    bool search_(int i, int j, std::vector<std::vector<char>>& board, std::string& word, int k = 0) {
        if (k == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i == board.size() || j == board[0].size()) {
            return false;
        }

        if (board[i][j] != word[k]) {
            return false;
        }

        auto ch = board[i][j];
        board[i][j] = '#';
        auto is_found = search_(i, j + 1, board, word, k + 1)
                     || search_(i, j - 1, board, word, k + 1)
                     || search_(i + 1, j, board, word, k + 1)
                     || search_(i - 1, j, board, word, k + 1);
        board[i][j] = ch;

        return is_found;
    }
};


int main() {
    return 0;
}
