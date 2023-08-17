#include <algorithm>
#include <iostream>


class Solution {
public:
    void _permutation(
        std::vector<int>& vec,
        size_t begin,
        size_t end,
        std::vector<std::vector<int>>& output
    ){
        if(begin >= end - 1){
            output.push_back(vec);
            return;
        }

        for(size_t i = begin; i < end; ++i){
            std::swap(vec[begin], vec[i]);
            _permutation(vec, begin + 1, end, output);
            std::swap(vec[begin], vec[i]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& vec) {
        std::vector<std::vector<int>> result;
        _permutation(vec, 0, vec.size(), result);

        return result;
    }
};


int main() {
    
    return 0;
}
