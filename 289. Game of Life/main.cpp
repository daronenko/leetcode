#include <algorithm>
#include <vector>


class Solution {
 public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int rows = board.size();
        int cols = rows ? board[0].size() : 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int alive_count = 0;
                for (int i_ = std::max(i - 1, 0); i_ < std::min(i + 2, cols); ++i_) {
                    for (int j_ = std::max(j - 1, 0); j_ < std::min(j + 2, rows); ++j_) {
                        alive_count += board[i_][j_] & 1;
                    }
                }

                if (alive_count == 3 || alive_count - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};


int main() {
    return 0;
}
