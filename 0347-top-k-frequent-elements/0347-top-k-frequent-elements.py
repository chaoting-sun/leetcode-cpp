class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_count = collections.defaultdict(int)
        max_freq = 0
        for num in nums:
            num_count[num] += 1
            max_freq = max(max_freq, num_count[num])

        buckets = [[] for _ in range(max_freq + 1)]
        for num, count in num_count.items():
            buckets[count].append(num)

        ans = []
        for i in range(max_freq, 0, -1):
            for num in buckets[i]:
                ans.append(num)
                if len(ans) == k:
                    return ans
        
        return ans

        