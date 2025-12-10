class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        vector<int> perfect_squares;
        for (int i = 1; i <= n; i++) {
            int is_perfect_square = (int)sqrt(i) * (int)sqrt(i) == i;
            if (is_perfect_square) {
                dp[i] = 1;
                perfect_squares.push_back(i);
            } else {
                for (int val: perfect_squares) {
                    if (dp[i - val] != -1) {
                        dp[i] = min(dp[i], dp[i - val] + 1);
                    }
                }
            }
        }

        return dp[n];
    }
};

// Dry run:

// base case: n = 1
// dp = [-1, -1], perfect_squares = []
// i == 1
// is_perfect_square = true
// dp[1] = 1, perfect_squares = [1]
// return dp[1] -> 1

// perfect square: n = 3
// dp[-1, -1, -1, -1], perfect_squares = []
// dp[-1, -1, -1, -1, -1], perfect_squares = []
// i == 1
// is_perfect_square = true
// dp[1] = 1, perfect_squares = [1]
// i == 2
// is_perfect_square = false
// dp[2] = min(INT_MAX, 1+1) = 2
// i == 3
// is_perfect_square = false

// perfect square: n = 4
// i == 3
// ...
// i == 4
// is_perfect_square = true
// dp[4] = 1