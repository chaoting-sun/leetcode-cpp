int MOD = 1e9 + 7;
using LL = long long;

class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        // dp[i][0..3]：處理到第 i 個元素（1-based）時，各狀態計數
        vector<vector<LL>> dp(n + 1, vector<LL>(4, 0));
        int E1 = 0, E2 = 1, O1 = 2, O2 = 3;

        for (int i = 1; i <= n; ++i) {
            int x = nums[i-1];
            // 先把「不選 x」的 carry 複製過來
            dp[i] = dp[i-1];

            if ((x & 1) == 0) { // even
                LL ne1 = (dp[i-1][E1] + dp[i-1][O1] + dp[i-1][O2] + 1) % MOD;
                LL ne2 = (dp[i-1][E2] + dp[i-1][E1]) % MOD;
                dp[i][E1] = ne1;
                dp[i][E2] = ne2;
            } else { // odd
                LL no1 = (dp[i-1][O1] + dp[i-1][E1] + dp[i-1][E2] + 1) % MOD;
                LL no2 = (dp[i-1][O2] + dp[i-1][O1]) % MOD;
                dp[i][O1] = no1;
                dp[i][O2] = no2;
            }
        }
        LL ans = 0;
        for (int s = 0; s < 4; ++s) ans = (ans + dp[n][s]) % MOD;
        return (int)ans;
    }

    // int countStableSubsequences(vector<int>& nums) {
    //     int n = nums.size();
    //     LL e1 = 0; // # sequences that ends with 1 even number
    //     LL e2 = 0; // # sequences that ends with 2 even numbers
    //     LL o1 = 0; // # sequences that ends with 1 odd number
    //     LL o2 = 0; // # sequences that ends with 2 odd numbers

    //     for (int i = 0; i < n; i++) {
    //         // odd
    //         if (nums[i] % 2 == 1) {
    //             LL next_o1 = (o1 + (e1 + e2 + 1)) % MOD;
    //             LL next_o2 = (o1 + o2) % MOD;
    //             o1 = next_o1;
    //             o2 = next_o2;
    //         }
    //         // even
    //         else {
    //             LL next_e1 = (e1 + (o1 + o2 + 1)) % MOD;
    //             LL next_e2 = (e1 + e2) % MOD;
    //             e1 = next_e1;
    //             e2 = next_e2;
    //         }
    //     }

    //     return (int)((o1 + o2 + e1 + e2) % MOD);
    // }
};
