class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid            
            # left subarray is increasing
            # use <= because when the subarray length is 2, left == mid (subarray of length 1 is in order)
            elif nums[left] <= nums[mid]:
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
        return -1

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