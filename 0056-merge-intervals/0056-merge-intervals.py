class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals

        intervals.sort()
        
        ans = []
        curr_start = intervals[0][0]
        curr_end = intervals[0][1]

        for interval in intervals:
            start, end = interval[0], interval[1]
            if curr_end >= start:
                curr_end = max(end, curr_end)
            else:
                ans.append([curr_start, curr_end])
                curr_start = start
                curr_end = end
        
        ans.append([curr_start, curr_end])
        return ans
