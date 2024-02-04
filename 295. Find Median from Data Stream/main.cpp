#include <functional>
#include <queue>
#include <vector>


class MedianFinder {
 public:
    void addNum(int num) {
        max_heap_.push(num);
        min_heap_.push(max_heap_.top());
        max_heap_.pop();

        if (min_heap_.size() > max_heap_.size()) {
            max_heap_.push(min_heap_.top());
            min_heap_.pop();
        }
    }

    double findMedian() {
        if (max_heap_.size() > min_heap_.size()) {
            return max_heap_.top();
        } else {
            return (max_heap_.top() + min_heap_.top()) / 2.0;
        }
    }

 private:
    std::priority_queue<int> max_heap_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_;
};


int main() {
    return 0;
}
