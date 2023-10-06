#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>


class LRUCache {
 public:
    explicit LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (!_map.contains(key)) {
            return -1;
        }

        _list.splice(_list.begin(), _list, _map[key]);
        return _map[key]->second;
    }

    void put(int key, int value) {
        if (_map.contains(key)) {
            _list.splice(_list.begin(), _list, _map[key]);
            _map[key]->second = value;
            return;
        }

        if (_list.size() == _capacity) {
            _map.erase(_list.back().first);
            _list.pop_back();
        }

        _list.push_front({key, value});
        _map[key] = _list.begin();
    }

 protected:
    int _capacity;
    std::list<std::pair<int, int>> _list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> _map;
};


int main() {
    LRUCache lru_cache(2);
    lru_cache.put(1, 1);
    lru_cache.put(2, 2);
    std::cout << lru_cache.get(1) << std::endl;
    lru_cache.put(3, 3);
    std::cout << lru_cache.get(2) << std::endl;
    lru_cache.put(4, 4);
    std::cout << lru_cache.get(1) << std::endl;
    std::cout << lru_cache.get(3) << std::endl;
    std::cout << lru_cache.get(4) << std::endl;
    return 0;
}
