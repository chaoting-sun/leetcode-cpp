class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = 0

        for i in range(len(nums)):
            if nums[i] != 0:
                nums[left], nums[i] = nums[i], nums[left]
                left += 1

'''
case: nums = [0]
'''

'''
case: nums = [0, 1, 2, 0]
left = 0
i = 0
i = 1
    nums = [1, 0, 2, 0]
    left = 1
i = 2
    nums = [1, 2, 0, 0]
    left = 2
'''