class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        curr_sum = 0
        min_length = inf

        for right in range(len(nums)):
            curr_sum += nums[right]
            while curr_sum >= target:
                min_length = min(min_length, right - left + 1)
                curr_sum -= nums[left]
                left += 1
        
        return 0 if min_length == inf else min_length

'''
test case:
nums = [2,3,1]
target = 3

trace:
left = 0
right = 0
    curr_sum = 2
right = 1
    curr_sum = 5
    min_length = 2
    curr_sum = 3
    left = 1
    min_length = 1
    curr_sum = 0
    left = 2
right = 2
    curr_sum = 1
< returns 1
'''