class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wordLength = beginWord.size();
        vector<unordered_set<char>> choices(wordLength);
        for (string& word: wordList) {
            for (int i = 0; i < wordLength; i++) {
                choices[i].insert(word[i]);
            }
        }
        
        unordered_set<string> wordSet;
        for (string& word: wordList) {
            wordSet.insert(word);
        }

        if (!wordSet.count(endWord)) return 0;

        unordered_set<string> fronts { beginWord };
        unordered_set<string> ends { endWord };
        wordSet.erase(beginWord);
        wordSet.erase(endWord);
        int steps = 1;

        while (!fronts.empty() && !ends.empty()) {
            if (fronts.size() > ends.size()) swap(fronts, ends);
            steps++;

            unordered_set<string> nextWords;
            for (auto& word: fronts) {
                auto curr = word;
                for (int i = 0; i < wordLength; i++) {
                    char org = curr[i];
                    for (char ch: choices[i]) {
                        curr[i] = ch;
                        if (ends.count(curr)) return steps;
                        if (!wordSet.count(curr)) continue;
                        nextWords.insert(curr);
                        wordSet.erase(curr);
                        cout << curr << endl;
                    }
                    curr[i] = org;
                }
            }
            fronts.swap(nextWords);
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