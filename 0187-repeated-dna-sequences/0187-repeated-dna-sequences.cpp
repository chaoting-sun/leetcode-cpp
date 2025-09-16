class Solution {
public:
    // Approach: Sliding Window
    // Time: O((N-L)*L)
    // Space: O((N-L)*L)

    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10;
        unordered_set<string> seen, repeatedPattern;

        for (int i = 0; i < (int)s.size() - L + 1; i++) { // N - L
            string pattern = s.substr(i, 10); // L
            if (seen.count(pattern)) {
                repeatedPattern.insert(pattern);
            } else {
                seen.insert(pattern);
            }
        }

        vector<string> ans;
        for (string pattern: repeatedPattern) ans.push_back(pattern);
        return ans;
    }
};