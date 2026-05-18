class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if len(gas) != len(cost):
            return -1
        
        n = len(gas)
        start_idx = 0
        total_gain = 0
        curr_gain = 0

        for i in range(n):
            total_gain += gas[i] - cost[i]
            curr_gain += gas[i] - cost[i]
            if curr_gain < 0:
                curr_gain = 0
                start_idx = i + 1
        return start_idx if total_gain >= 0 else -1