class Solution {
public:
    string removeSubstring(string s, int k) {
        string ans;

        for (char ch: s) {
            ans.push_back(ch);
            int n = ans.size();
            if (n >= 2 * k) {
                bool hasPattern = true;
                int right = n - k;
                int left = right - 1;
                for (int i = 0; i < k; i++) {
                    if (ans[left - i] != '(' || ans[right + i] != ')') {
                        hasPattern = false;
                        break;
                    }
                }
                if (hasPattern) {
                    ans.resize(n - 2 * k);
                }         
            }
        }

        return ans;
    }
};

