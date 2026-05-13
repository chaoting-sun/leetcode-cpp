class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if nums[0] > target:
            return 0
        elif nums[-1] < target:
            return len(nums)

        left = 0
        right = len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return right

'''
base case: nums = [1, 2], target = 0
trace: returns 0

base case: nums = [1, 2], target = 3
trace: returns 2

test case: nums = [1, 2], target = 2
trace:
l = 0, r = 1
    m = 0
    l = 1
returns 1

test case: nums = [1, 2], target = 1
trace:
l = 0, r = 1
    m = 0
    r = 0
returns 0

test case: nums = [1, 2, 4], target = 3
l = 0, r = 2
    m = 1
    l = 1
l = 1, r = 2
    m = 1
    l = 2
returns 2
'''


'''
first element i larger than or equal to target -> i
F ... F T ... T
  l           r
        r
        l
'''