#include <string>
#include <memory>
#include <array>


class Trie {
 public:
    Trie(): root_(std::make_shared<node_t>(node_t{})) {}

    void insert(std::string word) {
        auto current_node = root_;

        for (auto ch : word) {
            if (!current_node->children_[ch - 'a']) {
                current_node->children_[ch - 'a'] = std::make_shared<node_t>(node_t{});
            }

            current_node = current_node->children_[ch - 'a'];
        }

        current_node->end_of_word = true;
    }

    bool search(std::string word) {
        auto current_node = root_;

        for (auto ch : word) {
            if (!current_node->children_[ch - 'a']) {
                return false;
            }

            current_node = current_node->children_[ch - 'a'];
        }

        return current_node->end_of_word;
    }

    bool startsWith(std::string prefix) {
        auto current_node = root_;

        for (auto ch : prefix) {
            if (!current_node->children_[ch - 'a']) {
                return false;
            }

            current_node = current_node->children_[ch - 'a'];
        }

        return true;
    }

 private:
    struct node_t {
        std::array<std::shared_ptr<node_t>, 26> children_;
        bool end_of_word = false;
    };

    std::shared_ptr<node_t> root_;
};


int main() {
    return 0;
}
