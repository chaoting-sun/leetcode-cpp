class Solution {
public:
    // Approach: DP -> wrong solution
    // definition of dp[i]: the number of ways to make up i money
    // transition state function: dp[i] = dp[i - coins[0]] + dp[i - coins[1]] + ... + dp[i - coins[n-1]]
    // initialization: dp[amount + 1]; dp[0] = 1
    // result: dp[amount]

    // dp[0] = 1
    // dp[1] = dp[1-1] = 1
    // dp[2] = dp[2-1] + dp[2-2] = dp[1] + dp[0] = 1 + 1 = 2 -> 1,1; 2
    // dp[3] = dp[3-1] + dp[3-2] = dp[2] + dp[1] = 2 + 1 = 3 -> 2,1; 1,1,1; 1,2 -> 2,1 and 1,2 are the same
    // dp[4] = dp[4-1] + dp[4-2] = dp[3] + dp[1] = 3 + 1 = 4
    // dp[5] = dp[5-1] + dp[5-2] + dp[5-5] = 4 + 3 + 1 = 8
    
    // int change(int amount, vector<int>& coins) {
    //     vector<int> dp(amount + 1, -1);

    //     dp[0] = 1;
    //     for (int curr = 1; curr <= amount; curr++) {
    //         for (int c: coins) {
    //             if (curr >= c) {
    //                 dp[curr] += dp[curr - c];
    //             }
    //         }
    //     }

    //     return dp[amount];
    // }

    // Approach: DP -> correct solution
    // definition of dp[i][j]: the number of ways to make up i money using 0 ~ j coins
    // transition state function: dp[i][j]
    //      - j coin is not selected -> dp[i][j-1]
    //      - j coin is selected -> dp[i - coins[j]][j]
    // initialization: dp[0][0], dp[0][1], ..., dp[0][n-1] = 1, dp[1][0], dp[2][0], ..., dp[amount][0] = 0
    // result: dp[amount][n]

    // Time: O(amount * #coins)
    // Space: O(amount * #coins)

    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<unsigned long long>> dp(amount + 1, vector<unsigned long long>(n + 1, 0));

    //     for (int j = 0; j <= n; j++) dp[0][j] = 1;

    //     for (int i = 1; i <= amount; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             dp[i][j] = dp[i][j - 1];
    //             if (i >= coins[j - 1]) {
    //                 dp[i][j] += dp[i - coins[j - 1]][j];
    //             }
    //         }
    //     }

    //     return dp[amount][n] <= INT_MAX ? dp[amount][n] : -1;
    // }

    // optimize ()

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;

        for (int coin: coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount] <= INT_MAX ? dp[amount] : -1;
    }
};
