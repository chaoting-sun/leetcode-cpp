# class Solution:
#     def subarraySum(self, nums: List[int], k: int) -> int:
#         prefix = [0]
#         for n in nums:
#             prefix.append(prefix[-1] + n)

#         count = 0
#         for j in range(1, len(prefix)):
#             for i in range(j):
#                 if prefix[j] - prefix[i] == k:
#                     count += 1
        
#         return count


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # prefix[j] - prefix[i] = k -> prefix[i] = prefix[j] - k

        ans = 0
        prefix_sum = 0
        
        prefix_count = defaultdict(int)
        prefix_count[0] = 1
        
        for val in nums:
            prefix_sum += val
            key = prefix_sum - k
            if key in prefix_count:
                ans += prefix_count[key]
            prefix_count[p] += 1

        return ans