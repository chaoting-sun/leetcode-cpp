# find the largest right value that is larger than the current value

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        
        max_right_val = prices[-1]
        max_profit = 0
        for i in range(len(prices) - 2, -1, -1):
            max_profit = max(max_profit, max_right_val - prices[i])
            max_right_val = max(max_right_val, prices[i])
        
        return max_profit