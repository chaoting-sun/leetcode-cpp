class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = INT_MIN;
        for (string& str: strs) {
            bool hasAlpha = false;
            for (char c: str) {
                if (isalpha(c)) {
                    hasAlpha = true;
                    break;
                }
            }
            if (hasAlpha) {
                ans = max((int)str.size(), ans);
            } else {
                ans = max(stoi(str), ans);
            }
        }
        return ans;
    }
};