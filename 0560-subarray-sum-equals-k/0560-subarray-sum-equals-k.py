class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if not nums:
            return 0
        
        seen = defaultdict(int)
        prefix = 0
        seen[0] = 1
        count = 0

        for i in range(len(nums)):
            prefix += nums[i]
            count += seen[prefix - k]
            seen[prefix] += 1
        
        return count


'''
nums = [1, 1, 1]
k = 2

i = 0
    prefix = 1
    count = 0
    seen = { 0: 1, 1: 1 }
i = 1
    prefix = 2
    count = 1
    seen = { 0: 1, 1: 1, 2: 1 }
i = 2
    prefix = 3
    count = 2
    seen = { 0: 1, 1: 1, 2: 2 }
< returns 2
'''