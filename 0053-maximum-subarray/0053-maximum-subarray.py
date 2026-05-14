class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr_prefix = 0
        min_prefix = 0
        max_sum = -inf

        for n in nums:
            curr_prefix += n
            max_sum = max(max_sum, curr_prefix - min_prefix)
            min_prefix = min(min_prefix, curr_prefix)

        return max_sum

'''
test case: nums = [-1, 2, -1, 2]
trace:
curr prefix = 0
min prefix = 0
max sum = 0

iterate nums
    update curr prefix
    update max sum
    update min prefix
'''