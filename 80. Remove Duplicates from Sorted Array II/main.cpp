#include <iostream>
#include <vector>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (i < 2 || nums[i - 2] != nums[j]) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};


int main() {
    return 0;
}

