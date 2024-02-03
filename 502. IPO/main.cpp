#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <utility>


// class Solution {
//  public:
//     int findMaximizedCapital(
//         int k,
//         int w,
//         std::vector<int>& profits,
//         std::vector<int>& capital
//     ) {
//         std::priority_queue<int> doables;
//         std::multiset<std::pair<int, int>> undoables;
//
//         for (int i = 0; i < profits.size(); ++i) {
//             if (profits[i] <= 0) {
//                 continue;
//             }
//
//             if (capital[i] <= w) {
//                 doables.push(profits[i]);
//             } else {
//                 undoables.emplace(capital[i], profits[i]);
//             }
//         }
//
//         while (k-- && !doables.empty()) {
//             w += doables.top();
//             doables.pop();
//
//             for (auto& project : undoables) {
//                 if (project.first <= w) {
//                     doables.push(project.second);
//                     undoables.erase(undoables.lower_bound(project));  // lower bound is used to remove the first value only
//                 }
//             }
//         }
//
//         return w;
//     }
// };


class Solution {
 public:
    int findMaximizedCapital(
        int k,
        int w,
        std::vector<int>& profits,
        std::vector<int>& capital
    ) {
        std::vector<std::pair<int, int>> projects;
        projects.reserve(profits.size());

        for (int i = 0; i < profits.size(); ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        std::sort(projects.begin(), projects.end());

        int idx = 0;
        std::priority_queue<int> max_heap;
        for (int i = 0; i < k; ++i) {
            while (idx < profits.size() && projects[idx].first <= w) {
                max_heap.push(projects[idx].second);
                ++idx;
            }

            if (max_heap.empty()) {
                break;
            }

            w += max_heap.top();
            max_heap.pop();
        }

        return w;
    }
};


int main() {
    return 0;
}
