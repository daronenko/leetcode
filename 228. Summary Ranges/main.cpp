#include <string>
#include <vector>


class Solution {
 public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;

        int left = 0, right;
        while (left < nums.size()) {
            right = left + 1;
            while (right < nums.size() && nums[right] - nums[right - 1] == 1) {
                ++right;
            }

            std::string token = std::to_string(nums[left])
                + (right - left > 1
                ? "->" + std::to_string(nums[right - 1])
                : "");
            result.push_back(token);
            left = right;
        }

        return result;
    }
};


int main() {
    return 0;
}
