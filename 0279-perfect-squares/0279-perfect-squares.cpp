class Solution {
public:
    int numSquares(int n) {
        vector<int> perfect_squares;
        for (int i = 1; i * i <= n; i++) {
            perfect_squares.push_back(i * i);
        }

        // any number can at least be composed of by 1s
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int square: perfect_squares) {
                if (i < square)
                    break;
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }

        return dp[n];
    }
};

// Dry run:

// n = 12
// perfect_squares = [1, 4, 9]
// dp[0] = 0
// i = 1
// square = 1
// dp[1] = min(12, 0 + 1) = 1
// i = 2
// square = 1
// dp[2] = min(12, dp[1] + 1) = 2
// i = 3
// square = 1
// dp[3] = min(12, dp[2] + 1) = 3
// i = 4
// square = 1
// dp[4] = min(12, dp[3] + 1) = 4
// square = 4
// dp[4] = min(4, dp[0] + 1) = 1
