#include <vector>


class Solution {
 public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    _dfs(grid, i, j);
                }
            }
        }

        return islands;
    }

 private:
    void _dfs(std::vector<std::vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0';

        _dfs(grid, i + 1, j);
        _dfs(grid, i - 1, j);
        _dfs(grid, i, j + 1);
        _dfs(grid, i, j - 1);
    }
};


int main() {
    return 0;
}
