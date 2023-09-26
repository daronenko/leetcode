#include <stack>
#include <limits>


class MinStack {
 public:
    void push(int val) {
        if (val <= _min_val) {
            _stack.push(_min_val);
            _min_val = val;
        }

        _stack.push(val);
    }

    void pop() {
        if (_stack.top() == _min_val) {
            _stack.pop();
            _min_val = _stack.top();
        }

        _stack.pop();
    }

    int top() {
        return _stack.top();
    }

    int getMin() {
        return _min_val;
    }

 protected:
    std::stack<int> _stack;
    int _min_val = std::numeric_limits<int>::max();
};


int main() {
    return 0;
}
