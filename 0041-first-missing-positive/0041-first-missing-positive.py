class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while 1 <= nums[i] <= len(nums) and nums[i] != i + 1 and nums[i] != nums[nums[i] - 1]:
                correct_idx = nums[i] - 1
                nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1

'''
test case: [3,4,-1,1]
trace:
i = 0
    [3,4,-1,1]
    [-1,4,3,1]
i = 1
    [-1,4,3,1]
    [-1,1,3,4]
    [1,-1,3,4]
i = 2
    [1,-1,3,4]
i = 3
    [1,-1,3,4]
'''