class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            # left subarray is increasing
            if nums[left] <= nums[mid]:
                if nums[left] <= target and target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            # right subarray is increasing
            else:
                if nums[mid] <= target and target <= nums[right]:
                    left = mid
                else:
                    right = mid - 1
        
        return left if target == nums[left] else -1

# target = 3
# 4 5 0 1 2 3
#           r
#         l
#         m

# 0 1 2 3 4 5
# l         r
#     m

# 2 3 4 5 0 1
# l         r
#     m

# 4 5 8 9 0 3
# l         r
#     m