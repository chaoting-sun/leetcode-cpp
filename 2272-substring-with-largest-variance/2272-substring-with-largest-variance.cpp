class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        int ans = 0;

        unordered_set<int> Set(s.begin(), s.end());
        
        for (char a: Set) {
            for (char b: Set) {
                if (a == b) continue;
                int dp0 = 0, dp1 = INT_MIN / 2;
                for (int k = 0; k < n; k++) {
                    if (s[k] == a) {
                        dp0++;
                        dp1++;
                    } else if (s[k] == b) {
                        dp1 = max(dp0 - 1, dp1 - 1);
                        dp0 = 0;
                    }
                    ans = max(ans, dp1);
                }                
            }
        }

        return ans;
    }
};

// // abcde
// bc
// dp0 = []
// dp1 = []



// dp0[i] -> the max subarray sum ending at i and does not contain -1
// dp1[i] -> the max subarray sum ending at i and contains -1