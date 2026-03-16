class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        needed = {}
        for i, v in enumerate(nums):
            if v in needed:
                return [needed[v], i]
            needed[target - v] = i
        return []
            