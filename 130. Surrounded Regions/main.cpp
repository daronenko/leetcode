#include <vector>


class Solution {
 public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty()) {
            return;
        }

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                _capture(board, i, 0);
            }
            if (board[i][cols - 1] == 'O') {
                _capture(board, i, cols - 1);
            }
        }

        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') {
                _capture(board, 0, j);
            }
            if (board[rows - 1][j] == 'O') {
                _capture(board, rows - 1, j);
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] != 'S') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }

 private:
    void _capture(std::vector<std::vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'S';

        _capture(board, i + 1, j);
        _capture(board, i - 1, j);
        _capture(board, i, j + 1);
        _capture(board, i, j - 1);
    }
};


int main() {
    return 0;
}
