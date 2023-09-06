#include <vector>


class Solution {
 public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int col_0 = 1;
        for (int i = 0; i < matrix.size(); ++i) {
            if (!matrix[i][0]) {
                col_0 = 0;
            }
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }

        for (int i = matrix.size() - 1; i >= 0; --i) {
            for (int j = matrix[0].size() - 1; j >= 1; --j) {
                if (!matrix[0][j] || !matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }
            if (!col_0) {
                matrix[i][0] = 0;
            }
        }
    }
};


int main() {
    return 0;
}
