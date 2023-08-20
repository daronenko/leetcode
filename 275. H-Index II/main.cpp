#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int result;
        
        int len = citations.size();
        int left = 0, right = len - 1, middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (citations[middle] < len - middle) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return len - left;
    }
};


int main() {
    Solution sol;
    {
        std::vector<int> citations{0, 1, 3, 5, 6};
        std::cout << sol.hIndex(citations) << std::endl;
    }
    {
        std::vector<int> citations{1, 2, 100};
        std::cout << sol.hIndex(citations) << std::endl;
    }
    return 0;
}

