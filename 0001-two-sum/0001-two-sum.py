class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        needed = {}
        for i, n in enumerate(nums):
            if n in needed:
                return [needed[n], i]
            needed[target - n] = i
        return []