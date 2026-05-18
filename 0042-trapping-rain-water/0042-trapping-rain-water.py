class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n <= 2:
            return 0
        
        left_max = height[0]
        right_max = height[n - 1]
        left = 1
        right = n - 2
        water = 0

        while left <= right:
            left_max = max(left_max, height[left])
            right_max = max(right_max, height[right])
            border_height = min(left_max, right_max)
            if left_max <= right_max:
                water += (border_height - height[left]) if border_height >= height[left] else 0
                left += 1
            else:
                water += (border_height - height[right]) if border_height >= height[right] else 0
                right -= 1
        return water

'''
test case: [0,1,0,2,1,0,1,3,2,1,2,1]
                          l
                          r
lmax = 3
rmax = 2
border_h = 2
water = 0 + 1 + 0 + 1 + 2 + 1 + 0 + 1 + 0
'''