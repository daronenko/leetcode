#include <iostream>
#include <vector>


class Solution {
 public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size(), m = n ? matrix[0].size() : 0;
        int upper = 0, down = n - 1, left = 0, right = m - 1;

        std::vector<int> result(n * m);
        int curr = 0;
        while (upper <= down && left <= right) {
            for (int col = left; col <= right; ++col) {
                result[curr++] = matrix[upper][col];
            }
            if (++upper > down) {
                break;
            }

            for (int row = upper; row <= down; ++row) {
                result[curr++] = matrix[row][right];
            }
            if (--right < left) {
                break;
            }

            for (int col = right; col >= left; --col) {
                result[curr++] = matrix[down][col];
            }
            if (--down < upper) {
                break;
            }

            for (int row = down; row >= upper; --row) {
                result[curr++] = matrix[row][left];
            }
            if (left++ > right) {
                break;
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
