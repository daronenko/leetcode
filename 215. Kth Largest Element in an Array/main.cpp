#include <algorithm>
#include <functional>
#include <vector>
#include <queue>


class Solution {
 public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::nth_element(
            nums.begin(),
            nums.end() + k - 1,
            nums.end(),
            std::greater<int>()
        );
        return nums[k - 1];
    }
};


// class Solution {
//  public:
//     int findKthLargest(std::vector<int>& nums, int k) {
//         std::make_heap(nums.begin(), nums.end());
//         for (int i = 0; i < k - 1; ++i) {
//             std::pop_heap(nums.begin(), nums.end());
//             nums.pop_back();
//         }
//         std::pop_heap(nums.begin(), nums.end());
//         return nums.back();
//     }
// };


// class Solution {
//  public:
//     int findKthLargest(std::vector<int>& nums, int k) {
//         std::priority_queue heap(nums.begin(), nums.end(), std::greater<int>());
//
//         while (heap.size() > k) {
//             heap.pop();
//         }
//
//         return heap.top();
//     }
// };


int main() {
    return 0;
}
