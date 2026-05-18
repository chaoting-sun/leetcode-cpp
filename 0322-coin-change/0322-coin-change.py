class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        impossible_number = amount + 1
        dp = [impossible_number] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for c in coins:
                if i >= c and dp[i - c] != impossible_number:
                    dp[i] = min(dp[i], dp[i - c] + 1)
        return dp[amount] if dp[amount] != impossible_number else -1