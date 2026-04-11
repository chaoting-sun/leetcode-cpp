# class Solution:
#     def findMinFibonacciNumbers(self, k: int) -> int:
#         # gather numbers
#         fib_nums = [1, 1]
#         while True:
#             next_num = fib_nums[-2] + fib_nums[-1]
#             if next_num <= k:
#                 fib_nums.append(next_num)
#             else:
#                 break

#         # subtract from k
#         idx = len(fib_nums) - 1
#         count = 0
#         while k > 0:
#             if fib_nums[idx] > k:
#                 idx -= 1
#                 continue

#             k -= fib_nums[idx]
#             count += 1

#         return count


class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        a, b = 1, 1
        while b <= k:
            a, b = b, a + b
        
        count = 0
        while k > 0:
            if a <= k:
                k -= a
                count += 1
            else:
                a, b = b - a, a

        return count