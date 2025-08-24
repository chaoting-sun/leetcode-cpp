// Approach: DP (bottom-up)
// dp[i] means if the substring between 0 to i is valid (True/False)
// dp[i] = (s[(i - l_w1 + 1) ~ i] in wordset && dp[i - l_w1]) ||
//         (s[(i - l_w2 + 1) ~ i] in wordset && dp[i - l_w2]) ...
// Initialization: dp(n + 1); dp[0] = True

// Time: O(nml). n = s length; m = # words; l = word length
// Space: O(n)

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.size();
//         if (n == 0) return true;

//         vector<bool> dp(n + 1, false); // dp table is 1-indexed
//         dp[0] = true;

//         for (int i = 0; i < n; i++) { // index for s
//             for (string& w: wordDict) {
//                 int n_letters = w.size();
//                 if (n_letters > i + 1) continue;
//                 bool is_valid_suffix = s.substr(i - n_letters + 1, n_letters) == w;
//                 bool is_valid = dp[i - n_letters + 1] && is_valid_suffix;
//                 dp[i + 1] = dp[i + 1] || is_valid;
//                 if (is_valid) break;
//             }
//         }
//         return dp[n];
//     }
// };

// l e e t c o d e
// 0 1 2 3 4 5 6 7

// dp = t f f f t f f f t
//      0 1 2 3 4 5 6 7 8

// Approach: DP (top-bottom)

class Solution {
public:
    bool search(string s, vector<string>& wordDict, vector<int>& memo, int i) {
        if (memo[i] != -1) return memo[i] == 1;

        for (string& w: wordDict) {
            int n_letters = w.size();
            if (n_letters > i + 1) continue;
            if (s.substr(i - n_letters + 1, n_letters) == w && (n_letters == i + 1 || search(s, wordDict, memo, i - n_letters))) {
                memo[i] = 1;
                return true;
            }
        }
        
        memo[i] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if (n == 0) return true;

        vector<int> memo(n, -1);
        return search(s, wordDict, memo, n - 1);
    }
};
