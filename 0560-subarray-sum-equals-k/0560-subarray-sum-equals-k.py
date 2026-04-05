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
        prefix = 0
        # prefix_count[x]: the count of prefix sum = x before current position
        prefix_count = defaultdict(int)
        prefix_count[0] = 1
        
        for n in nums:
            prefix += n
            key = prefix - k
            ans += prefix_count[key] # default = 0
            prefix_count[prefix] += 1

        return ans