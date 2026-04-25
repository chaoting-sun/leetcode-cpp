class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        if not nums:
            return 0
        
        seen = defaultdict(int)
        prefix = 0
        seen[0] = 1
        count = 0

        for i in range(len(nums)):
            prefix += nums[i]
            rem = prefix % k
            if rem > 0:
                count += seen[(rem - k) % k]
            else:
                count += seen[0]
            seen[prefix % k] += 1
        
        return count

'''
nums = [4, 5,j ]


nums = [6, 2, -1, 3]
k = 5
seen = { 0: 1, 1: 1, 2: 1, 3: 1 }
'''