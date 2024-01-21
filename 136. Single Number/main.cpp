#include <iostream>
#include <vector>


class Solution {
 public:
    int singleNumber(std::vector<int>& nums) {
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            answer ^= nums[i];
        }

        return answer;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> vec{2, 2, 1};
        std::cout << sol.singleNumber(vec) << std::endl;
    }
    {
        std::vector<int> vec{4, 1, 2, 1, 2};
        std::cout << sol.singleNumber(vec) << std::endl;
    }
    {
        std::vector<int> vec{1};
        std::cout << sol.singleNumber(vec) << std::endl;
    }
    return 0;
}
