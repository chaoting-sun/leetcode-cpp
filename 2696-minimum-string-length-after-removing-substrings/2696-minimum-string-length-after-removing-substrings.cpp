class Solution {
public:
    int minLength(string s) {
        string ans;
        for (char c: s) {
            if (!ans.empty() &&
                (ans.back() == 'A' && c == 'B' ||
                 ans.back() == 'C' && c == 'D')) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans.size();
    }
};