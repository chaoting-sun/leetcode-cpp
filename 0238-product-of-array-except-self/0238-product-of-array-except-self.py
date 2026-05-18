class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [1] * len(nums)
        prefix = 1
        for i in range(1, len(nums)):
            prefix *= nums[i - 1]
            ans[i] = prefix
        suffix = 1
        for i in range(len(nums) - 2, -1, -1):
            suffix *= nums[i + 1]
            ans[i] *= suffix
        return ans

'''
test case: [1,2,3,4]
trace:
ans = [1,1,2,6]
pre = 1
i = 1
    pre = 1
i = 2
    pre = 2
i = 3
    pre = 6
ans = [24,12,8,6]
suff = 1
i = 2
    suff = 4
i = 1
    suff = 12
i = 0
    suff = 24
'''