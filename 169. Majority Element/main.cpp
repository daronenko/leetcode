#include <iostream>
#include <vector>
#include <cassert>


class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0, candidate;
        for (const int num: nums) {
            if (!count) {
                candidate = num;
            }
            
            if (num == candidate) {
                ++count;
            } else {
                --count;
            }
        }
        return candidate;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> nums{3, 2, 3};
        assert(3 == sol.majorityElement(nums));
    }
    {
        std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
        assert(2 == sol.majorityElement(nums));
    }
}

