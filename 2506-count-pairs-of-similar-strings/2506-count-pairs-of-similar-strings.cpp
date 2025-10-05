class Solution {
public:
    int similarPairs(vector<string>& words) {
        for (auto& word: words) {
            sort(word.begin(), word.end());
        }
        vector<string> uniqueCharWords;
        for (auto& word: words) {
            string c = "";
            for (char w: word) {
                if (c == "" || c.back() != w) c += w;
            }
            uniqueCharWords.push_back(c);
        }
        unordered_map<string,int> cnts;
        for (auto& word: uniqueCharWords) {
            cnts[word]++;
        }
        int ans = 0;
        for (auto& [word, c]: cnts) {
            ans += c * (c - 1) / 2;
        }
        return ans;
    }
};