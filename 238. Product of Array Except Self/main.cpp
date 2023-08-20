#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer;
        int len = nums.size();
        answer.resize(len);

        answer[0] = 1;
        for (int i = 1; i < len; ++i) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int current_suffix_product = 1;
        for (int i = len - 1; i >= 0; --i) {
            answer[i] *= current_suffix_product;
            current_suffix_product *= nums[i];
        }

        return answer;
    }
};


int main() {
    return 0;
}

