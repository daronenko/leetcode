#include <string>
#include <memory>
#include <array>
#include <iostream>


class WordDictionary {
 public:
    WordDictionary(): root_(std::make_shared<node_t>(node_t{})) {}

    void addWord(std::string word) {
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
        return search_helper_(word, 0, root_);
    }

 private:
    struct node_t {
        std::array<std::shared_ptr<node_t>, 26> children_;
        bool end_of_word = false;
    };

    std::shared_ptr<node_t> root_;

    bool search_helper_(
        const std::string& word,
        std::size_t i,
        const std::shared_ptr<node_t> node
    ) {
        auto current_node = node;
        for (; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (auto child : current_node->children_) {
                    if (child && search_helper_(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!current_node->children_[word[i] - 'a']) {
                    return false;
                }
                current_node = current_node->children_[word[i] - 'a'];
            }
        }

        return current_node->end_of_word;
    }
};


int main() {
    auto wd = WordDictionary();
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    std::cout << wd.search("pad") << std::endl;
    std::cout << wd.search("bad") << std::endl;
    std::cout << wd.search(".ad") << std::endl;
    std::cout << wd.search("b..") << std::endl;
    return 0;
}
