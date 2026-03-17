class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        n = len(nums)
        if n < 3:
            return []
        
        ans = []
        nums.sort()

        for i in range(n):
            if i != 0 and nums[i - 1] == nums[i]:
                continue
            
            left = i + 1
            right = n - 1
            target = -nums[i]

            while left < right:
                s = nums[left] + nums[right]
                if s > target:
                    right -= 1
                elif s < target:
                    left += 1
                else:
                    ans.append([ nums[i], nums[left], nums[right] ])
                    left += 1
                    right -= 1
                    while left < right and nums[left - 1] == nums[left]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
        
        return ans