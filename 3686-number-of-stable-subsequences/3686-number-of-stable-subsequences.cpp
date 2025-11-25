int MOD = 1e9 + 7;

class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(2, vector<long long>(2, 0));
        int even = 0, odd = 1;
        int one = 0, two = 1;
        
        for (int i = 0; i < n; i++) {
            int isEven = nums[i] % 2 == 0;

            vector<vector<long long>> prevDP = dp;

            if (isEven) {
                dp[even][one] = (1 + prevDP[even][one] + prevDP[odd][one] + prevDP[odd][two]) % MOD;
                dp[even][two] = (prevDP[even][two] + prevDP[even][one]) % MOD;
            } else {
                dp[odd][one] = (1 + prevDP[even][one] + prevDP[odd][one] + prevDP[even][two]) % MOD;
                dp[odd][two] = (prevDP[odd][two] + prevDP[odd][one]) % MOD;
            }
            prevDP = dp;
        }
        long long total = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) total += dp[i][j];
        }
        return (int)(total % MOD);
    }
};

// class Solution {
// public:
//     int countStableSubsequences(vector<int>& nums) {
//         int n = nums.size();
//         long long dp0 = 0, dp1 = 0, dp00 = 0, dp11 = 0;
        
//         for (int i = 0; i < n; i++) {
//             int isEven = nums[i] % 2 == 0;

//             int prev_dp0 = dp0;
//             int prev_dp1 = dp1;

//             if (isEven) {
//                 dp0 = (1 + prev_dp0 + prev_dp1 + dp11) % MOD;
//                 dp00 = (dp00 + prev_dp0) % MOD;
//             } else {
//                 dp1 = (1 + prev_dp0 + prev_dp1 + dp00) % MOD;
//                 dp11 = (dp11 + prev_dp1) % MOD;
//             }
//         }
//         return (int)((dp0 + dp1 + dp00 + dp11) % MOD);
//     }
// };

// int dp0 = 1, dp1 = 0, dp00 = 0, dp01 = 0, dp10 = 0, dp11 = 0;

//    1 3 2
// 0  0 0 1
// 1  1 1 1
// 00 0 0 0
// 01 0 0 0
// 10 0 0 3
// 11 0 1 1

// 00 0 -> 0
// 01 0 -> 10
// 10 0 -> 00
// 11 0 -> 10

// 00 1 -> 01
// 01 1 -> 11
// 10 1 -> 01
// 11 1 -> 1