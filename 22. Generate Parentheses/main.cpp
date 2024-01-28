#include <vector>
#include <string>


class Solution {
 public:
    std::vector<std::string> generateParenthesis(int n) {
        std::string accumulated;
        generateParenthesis_(n, 0, 0, accumulated);
        return result_;
    }

 private:
    std::vector<std::string> result_;

    void generateParenthesis_(
        int n,
        int opened,
        int closed,
        std::string& accumulated
    ) {
        if (accumulated.size() == n * 2) {
            result_.push_back(accumulated);
            return;
        }

        if (opened < n) {
            accumulated.push_back('(');
            generateParenthesis_(n, opened + 1, closed, accumulated);
            accumulated.pop_back();
        }

        if (closed < opened) {
            accumulated.push_back(')');
            generateParenthesis_(n, opened, closed + 1, accumulated);
            accumulated.pop_back();
        }
    }
};


int main() {
    return 0;
}
