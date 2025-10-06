class Solution {
public:
    // Approach: stack
    // Time: O(n)
    // Space: O(n)

    string removeStars(string s) {
        string ans;
        for (char c: s) {
            if (!ans.empty() && ans.back() != '*' && c == '*') {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};