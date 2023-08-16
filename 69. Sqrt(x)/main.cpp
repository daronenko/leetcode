#include <iostream>
#include <cstdint>


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        
        int low = 1;
        int high = x;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (middle ==  x / middle) {
                return middle;
            } else if (middle > x / middle) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }

        return high;
    }
};


int main() {
    Solution sol;
    std::cout << sol.mySqrt(4) << std::endl;
    std::cout << sol.mySqrt(8) << std::endl;
    return 0;
}

