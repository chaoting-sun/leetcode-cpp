import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        hp = []
        for n in nums:
            heapq.heappush(hp, n)
            if len(hp) > k:
                heapq.heappop(hp)
        return hp[0]