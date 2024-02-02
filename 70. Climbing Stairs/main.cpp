class Solution {
 public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        for (int i = 0; i < n - 1; ++i) {
            int tmp = a;
            a += b;
            b = tmp;
        }

        return a;
    }
};


int main() {
    return 0;
}
