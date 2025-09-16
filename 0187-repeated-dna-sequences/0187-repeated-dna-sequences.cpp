class Solution {
public:
    // Approach: Sliding Window
    // Time: O((N-L)*L)
    // Space: O((N-L)*L)

    // vector<string> findRepeatedDnaSequences(string s) {
    //     int L = 10;
    //     unordered_set<string> seen, repeatedPattern;

    //     for (int i = 0; i < (int)s.size() - L + 1; i++) { // N - L
    //         string pattern = s.substr(i, 10); // L
    //         if (seen.count(pattern)) {
    //             repeatedPattern.insert(pattern);
    //         } else {
    //             seen.insert(pattern);
    //         }
    //     }

    //     vector<string> ans;
    //     for (string pattern: repeatedPattern) ans.push_back(pattern);
    //     return ans;
    // }

    // Approach: Sliding Window with Bit Manipulation
    // Time: O(L)
    // Space: O(L)

    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10;
        int bit = 2 * L;
        int mask = (1 << bit) - 1;
        unordered_map<char,int> char2bit = {
            { 'A', 0 }, // 00
            { 'T', 1 }, // 01
            { 'C', 2 }, // 10
            { 'G', 3 }, // 11
        };

        vector<string> ans;
        int n = s.size();
        if (n < L) return {};

        int pattern = 0;
        unordered_set<int> added; // pattern added before
        unordered_set<int> seen; // used to avoid repetitive addition to the ans
        
        for (int i = 0; i < L - 1; i++) {
            pattern = (pattern << 2 | char2bit[s[i]]) & mask;
        }

        for (int i = L - 1; i < n; i++) { // L
            pattern = ((pattern << 2) | char2bit[s[i]]) & mask;
            if (added.count(pattern)) {
                if (!seen.count(pattern)) {
                    seen.insert(pattern);
                    ans.push_back(s.substr(i - L + 1, L));
                }
            } else {
                added.insert(pattern);
            }
        }

        return ans;
    }
};
