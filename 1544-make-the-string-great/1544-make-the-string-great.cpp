class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (char c: s) {
            if (!ans.empty() && (ans.back() - 'A' == c - 'a' || ans.back() - 'a' == c - 'A')) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};