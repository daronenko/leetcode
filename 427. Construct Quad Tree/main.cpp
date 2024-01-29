#include <vector>


class Node {
 public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
 public:
    Node* construct(std::vector<std::vector<int>>& grid) {
        return construct_(0, 0, grid.size(), grid);
    }

 private:
    Node* construct_(int row, int col, int n, const std::vector<std::vector<int>>& grid) {
        bool is_same = true;
        for (int i = 0; i < n && is_same; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[row][col] != grid[row + i][col + j]) {
                    is_same = false;
                    break;
                }
            }
        }

        if (is_same) {
            return new Node(grid[row][col], true, nullptr, nullptr, nullptr, nullptr);
        }

        n /= 2;
        Node* top_left = construct_(row, col, n, grid);
        Node* top_right = construct_(row, col + n, n, grid);
        Node* bottom_left = construct_(row + n, col, n, grid);
        Node* bottom_right = construct_(row + n, col + n, n, grid);

        return new Node(0, false, top_left, top_right, bottom_left, bottom_right);
    }
};


int main() {
    return 0;
}
