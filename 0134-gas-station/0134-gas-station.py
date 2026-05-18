class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if len(gas) != len(cost):
            return -1
        
        n = len(gas)
        gain = [gas[i] - cost[i] for i in range(n)]

        # ensure if the answer exists before we search for it
        if sum(gain) < 0:
            return -1

        curr_gas = 0
        start_idx = 0
        for i, g in enumerate(gain):
            curr_gas += g
            if curr_gas < 0:
                curr_gas = 0
                start_idx = i + 1
        return start_idx