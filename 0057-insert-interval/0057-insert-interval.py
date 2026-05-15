class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        
        if n == 0:
            return [newInterval]
        
        ans = []
        idx = 0

        while idx < n and intervals[idx][1] < newInterval[0]:
            ans.append(intervals[idx])
            idx += 1

        merged_min = newInterval[0]
        merged_max = newInterval[1]
        while idx < n and intervals[idx][0] <= newInterval[1]:            
            merged_min = min(merged_min, intervals[idx][0])
            merged_max = max(merged_max, intervals[idx][1])
            idx += 1
        ans.append([merged_min, merged_max])

        while idx < n:
            ans.append(intervals[idx])
            idx += 1

        return ans

"""
test case: intervals = [[1,3]], newInterval = [4,4]
trace:
idx = 0
ans = [[1,3]]
idx = 1
merged_min = 4, merged_max = 4
ans = [[1,3], [4,4]]

test case: intervals = [[1,3]], newInterval = [0,0]
trace:
idx = 0
merged_min = 0, merged_max = 0
ans = [[0,0]]
ans = [[0,0], [1,3]]

test case: intervals = [[1,3], [6,9]], newInterval = [2,5]
trace:
idx = 0
ans = []
merged_min = 2, merged_max = 5
merged_min = 1, merged_max = 5
idx = 1
ans = [[1,5]]
idx = 2
ans = [[1,5], [6,9]]
"""