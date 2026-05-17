class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals

        ans = []
        intervals.sort()
        curr_start = intervals[0][0]
        curr_end = intervals[0][1]
        for interval in intervals:
            if interval[0] <= curr_end:
                curr_end = max(interval[1], curr_end)
            else:
                ans.append([curr_start, curr_end])
                curr_start = interval[0]
                curr_end = interval[1]
        ans.append([curr_start, curr_end])
        return ans