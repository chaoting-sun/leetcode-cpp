class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[left] <= nums[mid]:
                if nums[left] <= target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[mid] <= target <= nums[right]:
                    left = mid
                else:
                    right = mid - 1
            print(left, right)
        return left if nums[left] == target else -1

'''
test case: nums = [3 4 0 1 2], target = 0
trace:
    nums = [3 4 0 1 2]
                l
                r
                m
test case: nums = [1 2 3 4], target = 1
trace:
    nums = [1 2 3 4]
            l
            r
            m
test case: nums = [3 1 2], target = 1
trace:
    nums = [3 1 2]
              l
              r
              m
test case: nums = [1 2], target = 3
trace:
    nums = [1 2]
              l
              r
              m
'''