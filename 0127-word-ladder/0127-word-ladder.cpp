class Solution {
public:
    string formGeneric(string word, int p) {
        int n = word.size();
        return word.substr(0, p) + "*" + word.substr(p + 1, n - p - 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> all_comb_map;

        for (string word: wordList) {
            for (int i = 0; i < word.size(); i++) {
                string generic_str = formGeneric(word, i);
                all_comb_map[generic_str].push_back(word);
            }
        }

        queue<pair<string, int>> q; // current string
        unordered_set<string> visited;

        q.push({ beginWord, 1 });

        // BFS
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string word = q.front().first;
                int level = q.front().second;
                q.pop();

                for (int j = 0; j < word.size(); j++) {
                    string generic_str = formGeneric(word, j);
                    for (string word: all_comb_map[generic_str]) {
                        if (word == endWord) {
                            return level + 1;
                        }
                        if (!visited.count(word)) {
                            q.push({ word, level + 1 });
                            visited.insert(word);
                        }
                    }
                }
            }
        }

        return 0; // no such sequence
    }
};
