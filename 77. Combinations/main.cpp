#include <iostream>
#include <vector>


// backtracking
// class Solution {
// public:
//     void backtrack(
//         int start,
//         std::vector<int>& combo,
//         int n,
//         int target_len,
//         std::vector<std::vector<int>>& answer
//     ) {
//         if (combo.size() == target_len) {
//             answer.push_back(combo);
//             return;
//         }
//
//         for (int i = start; i < n + 1; ++i) {
//             combo.push_back(i);
//             backtrack(i + 1, combo, n, target_len, answer);
//             combo.pop_back();
//         }
//     }
//
//     std::vector<std::vector<int>> combine(int n, int k) {
//         std::vector<int> combo;
//         std::vector<std::vector<int>> answer;
//         backtrack(1, combo, n, k, answer);
//
//         return answer;
//     }
// };


// iterative
class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> combo(k, 0);

        int i = 0;
        while (i >= 0) {
            ++combo[i];
            if (combo[i] > n) {
                --i;
            } else if (i == k - 1) {
                result.push_back(combo);
            } else {
                ++i;
                combo[i] = combo[i - 1];
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
