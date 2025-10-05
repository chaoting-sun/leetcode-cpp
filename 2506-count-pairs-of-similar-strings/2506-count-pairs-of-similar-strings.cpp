class Solution {
public:
    // Approach: hash map
    // Time: O(n*k*logk)
    // Space: O(nk)

    // int similarPairs(vector<string>& words) {
    //     unordered_map<string, int> freq;
    //     for (auto& word: words) {
    //         set<char> chars;
    //         for (char w: word) chars.insert(w); // O(k*logk)
    //         string s;
    //         for (auto ch: chars) s += ch;
    //         freq[s]++;
    //     }
    //     int ans = 0;
    //     for (auto& [word, c]: freq) {
    //         ans += c * (c - 1) / 2;
    //     }
    //     return ans;
    // }

    int similarPairs(vector<string>& words) {
        unordered_map<int, int> freq;
        for (auto& word: words) {
            int mask = 0;
            for (char c: word) mask |= 1 << c - 'a';
            freq[mask]++;
        }
        int ans = 0;
        for (auto& [_, c]: freq) {
            ans += c * (c - 1) / 2;
        }
        return ans;
    }
};