class NumArray:

    def __init__(self, nums: List[int]):
        self.prefix = self.buildPrefix(nums)

    def buildPrefix(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []
        prefix = [nums[0]]
        for i in range(1, len(nums)):
            prefix.append(nums[i] + prefix[-1])
        return prefix

    def sumRange(self, left: int, right: int) -> int:
        leftPrefix = 0 if left == 0 else self.prefix[left - 1]
        rightPrefix = self.prefix[right]
        return rightPrefix - leftPrefix


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)