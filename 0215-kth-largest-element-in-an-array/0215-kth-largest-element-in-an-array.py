# time = nlogk

# import heapq
# class Solution:
#     def findKthLargest(self, nums: List[int], k: int) -> int:
#         hp = []
#         for n in nums:
#             heapq.heappush(hp, n)
#             if len(hp) > k:
#                 heapq.heappop(hp)
#         return hp[0]

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_val, max_val = inf, -inf
        for n in nums:
            min_val = min(min_val, n)
            max_val = max(max_val, n)
        count = [0] * (max_val - min_val + 1)
        for n in nums:
            count[n - min_val] += 1
        for i in range(max_val - min_val, -1, -1):
            k -= count[i]
            if k <= 0:
                return i + min_val
        return -1