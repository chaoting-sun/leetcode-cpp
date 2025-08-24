class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (amount == 0) return 0;

        vector<int> min_coins(amount + 1, 10001);
        sort(coins.begin(), coins.end());

        min_coins[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c: coins) {
                if (i - c >= 0) {
                    min_coins[i] = min(min_coins[i], min_coins[i - c] + 1);
                } else {
                    break;
                }
            }
        }

        return min_coins[amount] != 10001 ? min_coins[amount] : -1;
    }
};

// coin = [1,2,5], n = 3
// i = 1
// c = 1 dp[1] = 1
// -> 1

// i = 2
// c = 1 dp[2] = min(dp[2], dp[1] + 1) = 2
// c = 2 dp[2] = min(dp[2], dp[0] + 1) = 1
// -> 2

// i = 3
// c = 1 dp[3] = min(dp[3], dp[2] + 1) = 3
// c = 2 dp[3] = min(dp[3], dp[1] + 1) = 2
// -> 1, 2

// i = 4
// c = 1 dp[4] = min(dp[4], dp[3] + 1) = 3
// c = 2 dp[4] = min(dp[4], dp[2] + 1) = 2
// 2, 2
