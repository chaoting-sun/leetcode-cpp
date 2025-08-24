class Solution {
public:
    // Approach: DP
    // def. of dp[i]: the number of decode ways from 0 to i of s
    // initialization: dp[0] = 0, dp[1] = if s[0] is valid

    bool isValid(string& s) {
        int n = s.size();
        if (n == 1) {
            return s[0] != '0';
        } else {
            if (s[0] == '0') return false;
            int num = stoi(s);
            return num >= 1 && num <= 26;
        }
    }

    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> dp(n + 1, 0);
        string s1, s2;
        
        s1 = s.substr(0, 1);
        dp[1] = isValid(s1) ? 1 : 0;

        for (int i = 2; i <= n; i++) {
            s1 = s.substr(i - 1, 1);
            s2 = s.substr(i - 2, 2);

            if (isValid(s1) && dp[i - 1] != 0) {
                dp[i] += dp[i - 1];
            }
            if (isValid(s2)) {
                if (i == 2) {
                    dp[i] += 1;
                } else {
                    dp[i] += dp[i - 2];
                }
            }
        }
    
        return dp[n];
    }
};