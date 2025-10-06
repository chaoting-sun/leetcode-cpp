class Solution {
public:
    // Approach: Stack
    // Time: O(n)
    // Space: O(n - d). d is a total length for all duplicates

    string removeDuplicates(string s) {
        string ans;
        for (char c: s) {
            if (!ans.empty() && ans.back() == c) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};