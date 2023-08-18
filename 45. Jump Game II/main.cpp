#include <algorithm>
#include <iostream>
#include <vector>


// greedy bfs
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int max_reachable = 0, last_jump_pos = 0, jumps_count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            max_reachable = std::max(max_reachable, i + nums[i]);
            if (i == last_jump_pos) {
                last_jump_pos = max_reachable;
                ++jumps_count;
            }
        }
        return jumps_count;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{2, 3, 1, 1, 4};
        std::cout << sol.jump(nums) << std::endl;
    }
    {
        std::vector<int> nums{2, 3, 0, 1, 4};
        std::cout << sol.jump(nums) << std::endl;
    }
    return 0;
}

