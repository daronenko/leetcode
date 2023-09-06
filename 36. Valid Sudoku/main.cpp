#include <iostream>
#include <vector>


class Solution {
 public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int grid[9][9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int value = board[i][j] - '1';
                    int k = i / 3 * 3 + j / 3;
                    if (rows[i][value] || cols[j][value] || grid[k][value]) {
                        return false;
                    }

                    rows[i][value] = cols[j][value] = grid[k][value] = 1;
                }
            }
        }

        return true;
    }
};


int main() {
    return 0;
}
