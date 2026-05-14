class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        
        return -1

'''
case: nums=[1], target=1
trace: l=0,r=0,m=0 > returns 0

case: nums=[1], target=2
trace:
l=0,r=0,m=0 -> l=1
> returns -1

case: nums=[1,3], target=2
trace:
l=0,r=1,m=0 -> l=1
l=1,r=1,m=1 -> r=0
'''