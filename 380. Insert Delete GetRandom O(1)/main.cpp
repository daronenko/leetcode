#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>


class RandomizedSet {
public:
    bool insert(int val) {
        if (_index_table.find(val) != _index_table.end()) {
            return false;
        }

        _values.push_back(val);
        _index_table[val] = _values.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        if (_index_table.find(val) == _index_table.end()) {
            return false;
        }

        int last = _values.back();
        _index_table[last] = _index_table[val];
        _values[_index_table[val]] = last;
        _values.pop_back();
        _index_table.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return _values[rand() % _values.size()];
    }

private:
    std::vector<int> _values;
    std::unordered_map<int, int> _index_table;
};


int main() {
    RandomizedSet* obj = new RandomizedSet();

    std::cout << obj->insert(1) << std::endl;
    std::cout << obj->remove(2) << std::endl;
    std::cout << obj->insert(2) << std::endl;
    std::cout << obj->getRandom() << std::endl;
    std::cout << obj->remove(1) << std::endl;
    std::cout << obj->insert(2) << std::endl;
    std::cout << obj->getRandom() << std::endl;

    return 0;
}
