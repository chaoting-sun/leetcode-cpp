class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        minHeap = []
        for v in nums:
            heapq.heappush(minHeap, v)
            if len(minHeap) > k:
                heapq.heappop(minHeap)
        return minHeap[0]