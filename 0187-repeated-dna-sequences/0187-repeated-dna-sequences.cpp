class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen, repeatedPattern;
        for (int i = 0; i < (int)s.size() - 9; i++) {
            string pattern = s.substr(i, 10);
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