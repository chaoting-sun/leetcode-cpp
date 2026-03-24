class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n

        prefix = nums[0]
        for i in range(1, n):
            ans[i] = prefix
            prefix *= nums[i]
        
        suffix = nums[n - 1]
        for i in range(n - 2, -1, -1):
            ans[i] *= suffix
            suffix *= nums[i]
        
        return ans
