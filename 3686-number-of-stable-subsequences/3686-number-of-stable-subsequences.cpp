int MOD = 1e9 + 7;

class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        long long dp0 = 0, dp1 = 0, dp00 = 0, dp01 = 0, dp10 = 0, dp11 = 0;
        
        for (int i = 0; i < n; i++) {
            int isEven = nums[i] % 2 == 0;

            int prev_dp0 = dp0;
            int prev_dp1 = dp1;

            if (isEven) {
                dp0 += 1;
                dp00 += (prev_dp0 + dp10) % MOD;
                dp10 += (prev_dp1 + dp01 + dp11) % MOD;
            } else {
                dp1 += 1;
                dp11 += (prev_dp1 + dp01) % MOD;
                dp01 += (prev_dp0 + dp10 + dp00) % MOD;
            }
        }
        return (int)((dp0 + dp1 + dp00 + dp01 + dp10 + dp11) % MOD);
    }
};

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