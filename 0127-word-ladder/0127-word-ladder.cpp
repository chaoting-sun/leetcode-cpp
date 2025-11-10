class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<string> q; // word
        q.push(beginWord);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;

            for (int i = 0; i < size; i++) {
                string word = q.front();
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
                            q.push(word);
                            dict.erase(word);
                        }
                        word[l] = ch;
                    }
                    
                }
            }
        }

        return 0;
    }

    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     int wordLength = beginWord.size();
    //     vector<unordered_set<char>> choices(wordLength);
    //     for (string& word: wordList) {
    //         for (int i = 0; i < wordLength; i++) {
    //             choices[i].insert(word[i]);
    //         }
    //     }
        
    //     unordered_set<string> wordSet;
    //     for (string& word: wordList) {
    //         wordSet.insert(word);
    //     }

    //     queue<string> q;
    //     q.push(beginWord);
    //     int steps = 0;
        
    //     while (!q.empty()) {
    //         steps++;
    //         int sz = q.size();
    //         for (int i = 0; i < sz; i++) {
    //             string word = q.front();
    //             q.pop();
    //             if (word == endWord) return steps;
                
    //             for (int j = 0; j < wordLength; j++) {
    //                 string nextWord = word;
    //                 for (char ch: choices[j]) {
    //                     nextWord[j] = ch;
    //                     if (wordSet.count(nextWord)) {
    //                         q.push(nextWord);
    //                         wordSet.erase(nextWord);
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     return 0;
    // }
};