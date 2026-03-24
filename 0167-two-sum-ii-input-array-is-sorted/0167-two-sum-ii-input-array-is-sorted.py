class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        if n < 2:
            return []
        
        left = 0
        right = n - 1
        while left < right:
            curr_sum = numbers[left] + numbers[right]
            if curr_sum > target:
                right -= 1
            elif curr_sum < target:
                left += 1
            else:
                return [left + 1, right + 1]
        
        return []