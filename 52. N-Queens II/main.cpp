#include <vector>


class Solution {
 public:
    int result = 0;

    int totalNQueens(int n) {
        std::vector<bool> cols(n, false);
        std::vector<bool> pos_diag(2 * n - 1, false);
        std::vector<bool> neg_diag(2 * n - 1, false);

        totalNQueens_(n, 0, cols, pos_diag, neg_diag);

        return result;
    }

 private:
    void totalNQueens_(
        int n,
        int row,
        std::vector<bool>& cols,
        std::vector<bool>& pos_diag,
        std::vector<bool>& neg_diag
    ) {
        if (row == n) {
            ++result;
        }

        for (int col = 0; col < n; ++col) {
            int pos_diag_idx = col + row;
            int neg_diag_idx = col - row + n;

            if (cols[col] || pos_diag[pos_diag_idx] || neg_diag[neg_diag_idx]) {
                continue;
            }

            cols[col] = true;
            pos_diag[pos_diag_idx] = true;
            neg_diag[neg_diag_idx] = true;

            totalNQueens_(n, row + 1, cols, pos_diag, neg_diag);

            cols[col] = false;
            pos_diag[pos_diag_idx] = false;
            neg_diag[neg_diag_idx] = false;
        }
    }
};


int main() {
    return 0;
}
