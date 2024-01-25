#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_set>


class Solution {
 public:
    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        std::reverse(board.begin(), board.end());

        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(1, 0));

        std::unordered_set<int> visited;

        while (!q.empty()) {
            auto [square, moves] = q.front();
            q.pop();

            for (int i = 1; i < 7; ++i) {
                int next = square + i;
                auto [row, col] = get_position_(next, board.size());

                if (board[row][col] != -1) {
                    next = board[row][col];
                }

                if (next == board.size() * board.size()) {
                    return moves + 1;
                }

                if (!visited.contains(next)) {
                    visited.insert(next);
                    q.push(std::make_pair(next, moves + 1));
                }
            }
        }

        return -1;
    }

 private:
    std::pair<int, int> get_position_(int square, int board_size) {
        int row = (square - 1) / board_size;
        int col = (square - 1) % board_size;

        if (row % 2) {
            col = board_size - 1 - col;
        }

        return std::make_pair(row, col);
    }
};


int main() {
    return 0;
}
