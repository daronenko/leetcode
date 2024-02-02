// class Solution {
//  public:
//     int rangeBitwiseAnd(int left, int right) {
//         while (right > left) {
//             right &= right - 1;
//         }
//
//         return right & left;
//     }
// };


class Solution {
 public:
    int rangeBitwiseAnd(int left, int right) {
        if (!left) {
            return 0;
        }

        int count = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            count <<= 1;
        }

        return left * count;
    }
};


int main() {
    return 0;
}
