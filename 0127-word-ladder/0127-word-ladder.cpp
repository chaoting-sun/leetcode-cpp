class Solution {
public:
    // Approach: Graph + BFS

    // string formGeneric(string word, int p) {
    //     int n = word.size();
    //     return word.substr(0, p) + "*" + word.substr(p + 1, n - p - 1);
    // }

    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     unordered_map<string, vector<string>> all_comb_map;

    //     // Time: O(N * L^2)
    //     // Space: O(N * L^2). in worst case there are O(N*L) pattens, and each word appears
    //     // in L lists.
    //     for (string word: wordList) { // O(N)
    //         for (int i = 0; i < word.size(); i++) { // O(L)
    //             string generic_str = formGeneric(word, i); // O(L)
    //             all_comb_map[generic_str].push_back(word); // O(1)
    //         }
    //     }

    //     queue<pair<string, int>> q; // current string
    //     unordered_set<string> visited;

    //     q.push({ beginWord, 1 });

    //     // BFS
    //     // Time
    //     // - generate patterns: O(N * L^2). need O(L^2) for one word to generate patterns
    //     // - in worst case each pattern processes up to O(N) adjacent words. so there are
    //     // O(N) compared with O(N) adjacent words one character by character O(L), which
    //     // takes O(N^2 * L)
    //     while (!q.empty()) {
    //         int size = q.size();

    //         for (int i = 0; i < size; i++) {
    //             string word = q.front().first;
    //             int level = q.front().second;
    //             q.pop();

    //             for (int j = 0; j < word.size(); j++) {
    //                 string generic_str = formGeneric(word, j);
    //                 for (string word: all_comb_map[generic_str]) {
    //                     if (word == endWord) {
    //                         return level + 1;
    //                     }
    //                     if (!visited.count(word)) {
    //                         q.push({ word, level + 1 });
    //                         visited.insert(word);
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     return 0; // no such sequence
    // }

    // optimized

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<pair<string, int>> q; // word, level
        q.push({ beginWord, 1 });

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [word, level] = q.front();
                q.pop();
                if (word == endWord) {
                    return level;
                }

                // change each character in the word
                for (int l = 0; l < word.size(); l++) {
                    char ch = word[l];

                    // to different characters
                    for (int c = 0; c < 26; c++) {
                        word[l] = c + 'a';

                        if (dict.count(word)) {
                            q.push({ word, level + 1 });
                            dict.erase(word);
                        }
                        word[l] = ch;
                    }
                    
                }
            }
        }

        return 0;
    }
};
