#include <iostream>
#include <vector>


class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        size_t i = 0;
        for (size_t j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};


int main() {
    return 0;
}

