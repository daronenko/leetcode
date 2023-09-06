#include <algorithm>
#include <vector>


class Solution {
 public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        std::reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[0].size(); ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};


int main() {
    return 0;
}
