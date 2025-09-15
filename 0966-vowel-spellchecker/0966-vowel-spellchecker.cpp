class Solution {
private:
    string toLower(string s) {
        for (char &c: s) c = tolower(c);
        return s;
    }
    string deVowel(string s) {
        for (char &c: s) c = isVowel(c) ? '*' : c;
        return s;
    }
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;

        for (string& word: wordlist) {
            exact.insert(word);
            string loweredWord = toLower(word);
            string devoweledWord = deVowel(loweredWord);
            if (!caseMap.count(loweredWord)) caseMap[loweredWord] = word;
            if (!vowelMap.count(devoweledWord)) vowelMap[devoweledWord] = word;
        }

        vector<string> ans;
        for (string& query: queries) {
            if (exact.count(query)) {
                ans.push_back(query);
            } else {
                string loweredQuery = toLower(query);
                string devoweledQuery = deVowel(loweredQuery);

                if (caseMap.count(loweredQuery)) {
                    ans.push_back(caseMap[loweredQuery]);
                } else if (vowelMap.count(devoweledQuery)) {
                    ans.push_back(vowelMap[devoweledQuery]);
                } else {
                    ans.push_back("");
                }
            }
        }

        return ans;
    }
};