class Solution {
public:
    // Approach: handle 3 cases
    // - non-overlapping intervals at the left of newInterval
    // - overlapping intervals with newInterval
    // - non-overlapping intervals at the right of newInterval

    // Time: O(n)
    // Space: O(1)

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;

        if (n == 0) return { newInterval };

        vector<vector<int>> ans;

        // 1st case
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // 2nd case
        int min_left = newInterval[0];
        int max_right = newInterval[1];
        while (i < n && intervals[i][0] <= newInterval[1]) {
            min_left = min(min_left, intervals[i][0]);
            max_right = max(max_right, intervals[i][1]);
            i++;
        }
        ans.push_back({ min_left, max_right });

        // 3rd case
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};