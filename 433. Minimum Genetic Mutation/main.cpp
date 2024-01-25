#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>


class Solution {
 public:
    int minMutation(
        std::string start_gene,
        std::string end_gene,
        std::vector<std::string>& bank
    ) {
        std::unordered_set<std::string> mutations(bank.begin(), bank.end());

        if (!mutations.contains(end_gene)) {
            return -1;
        }

        std::queue<std::string> q;
        q.push(start_gene);

        int mutations_number = 0;
        while (!q.empty()) {
            auto backet_size = q.size();
            while (backet_size--) {
                auto mutation = q.front();
                q.pop();

                if (mutation == end_gene) {
                    return mutations_number;
                }

                mutations.erase(mutation);
                for (int i = 0; i < 8; ++i) {
                    auto possible_mutation = mutation;

                    for (const char gene : {'A', 'C', 'G', 'T'}) {
                        possible_mutation[i] = gene;
                        if (mutations.contains(possible_mutation)) {
                            q.push(possible_mutation);
                        }
                    }
                }
            }

            ++mutations_number;
        }

        return -1;
    }
};


int main() {
    Solution sol;
    std::vector<std::string> bank{"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    std::cout << sol.minMutation("AACCGGTT", "AACCGCTA", bank) << std::endl;
    return 0;
}
