class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<string,int> uniqueCharWords;
        for (auto& word: words) {
            set<char> chars;
            for (char w: word) chars.insert(w);
            string s;
            for (auto ch: chars) s += ch;
            uniqueCharWords[s]++;
        }
        int ans = 0;
        for (auto& [word, c]: uniqueCharWords) {
            ans += c * (c - 1) / 2;
        }
        return ans;
    }
};