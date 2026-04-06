class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        impossible_number = amount + 1
        dp = [impossible_number] * (amount + 1)
        dp[0] = 0
        
        for total in range(1, amount + 1):
            for coin in coins:
                if total >= coin and dp[total - coin] != impossible_number:
                    dp[total] = min(dp[total], dp[total - coin] + 1)
        
        return dp[amount] if dp[amount] != impossible_number else -1