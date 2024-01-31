#include <vector>


class Solution {
 public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0;
        int j = m - 1;
        while (j >= 0 && i < n) {
            int value = matrix[i][j];
            if (value == target) {
                return true;
            } else if (value < target) {
                ++i;
            } else {
                --j;
            }
        }

        return false;
    }
};


int main() {
    return 0;
}
