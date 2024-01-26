#include <string>
#include <vector>


class TrieNode {
 public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};


class Solution {
 public:
    std::vector<std::string> findWords(
        std::vector<std::vector<char>>& board,
        std::vector<std::string>& words
    ) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }

        int m = board.size();
        int n = board[0].size();

        TrieNode* node = root_;
        std::vector<std::string> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, i, j, m, n, node, "", result);
            }
        }

        return result;
    }

 private:
    TrieNode* root_ = new TrieNode();

    void insert(std::string word) {
        TrieNode* node = root_;
        int curr = 0;

        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == nullptr) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }

        node->isWord = true;
    }

    void search(
        std::vector<std::vector<char>>& board,
        const int i,
        const int j,
        const int m,
        const int n,
        TrieNode* node,
        std::string word,
        std::vector<std::string>& result
    ) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') {
            return;
        }

        char c = board[i][j];
        node = node->children[c - 'a'];
        if (!node) {
            return;
        }

        word += board[i][j];
        if (node->isWord) {
            result.push_back(word);
            node->isWord = false;
        }

        board[i][j] = '#';

        search(board, i - 1, j, m, n, node, word, result);
        search(board, i + 1, j, m, n, node, word, result);
        search(board, i, j - 1, m, n, node, word, result);
        search(board, i, j + 1, m, n, node, word, result);

        board[i][j] = c;
    }
};


int main() {
    return 0;
}
