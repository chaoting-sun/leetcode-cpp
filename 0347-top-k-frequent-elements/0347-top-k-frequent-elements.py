from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = defaultdict(int)
        max_count = 0
        for n in nums:
            count[n] += 1
            max_count = max(max_count, count[n])
        count_bucket = defaultdict(list)
        for v, cnt in count.items():
            count_bucket[cnt].append(v)
        ans = []
        for cnt in range(max_count, 0, -1):
            if cnt in count_bucket:
                for v in count_bucket[cnt]:
                    ans.append(v)
                    if len(ans) == k:
                        return ans
        return ans