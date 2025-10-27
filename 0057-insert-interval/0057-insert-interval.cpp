class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        // find the first interval with interval[1] >= newInterval[0]
        int left = -1, right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][1] >= newInterval[0]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        int firstIdx = right;

        // find the last interval with interval[0] <= newInterval[1]
        left = -1;
        right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][0] <= newInterval[1]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int lastIdx = left;

        vector<vector<int>> ans;
        if (lastIdx == -1) {
            ans.push_back(newInterval);
            for (auto& iv: intervals) ans.push_back(iv);
        } else if (firstIdx == n) {
            for (auto& iv: intervals) ans.push_back(iv);
            ans.push_back(newInterval);
        } else if (lastIdx < firstIdx) {
            for (int i = 0; i <= lastIdx; i++) ans.push_back(intervals[i]);
            ans.push_back(newInterval);
            for (int i = firstIdx; i < n; i++) ans.push_back(intervals[i]);
        } else {
            int minStart = min(intervals[firstIdx][0], newInterval[0]);
            int maxEnd = max(intervals[lastIdx][1], newInterval[1]);
            for (int i = 0; i < n; i++) {
                if (i < firstIdx || i > lastIdx) {
                    ans.push_back(intervals[i]);
                } else if (i == firstIdx) {
                    ans.push_back({ minStart, maxEnd });
                }
            }
        }
        return ans;
    }

    //             -- ---- ----- ----
    //  --------


    // Approach: handle 3 cases
    // - non-overlapping intervals at the left of newInterval
    // - overlapping intervals with newInterval
    // - non-overlapping intervals at the right of newInterval

    // Time: O(n)
    // Space: O(1)

    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     int n = intervals.size();
    //     int i = 0;

    //     if (n == 0) return { newInterval };

    //     vector<vector<int>> ans;

    //     // 1st case
    //     while (i < n && intervals[i][1] < newInterval[0]) {
    //         ans.push_back(intervals[i]);
    //         i++;
    //     }

    //     // 2nd case
    //     int min_left = newInterval[0];
    //     int max_right = newInterval[1];
    //     while (i < n && intervals[i][0] <= newInterval[1]) {
    //         min_left = min(min_left, intervals[i][0]);
    //         max_right = max(max_right, intervals[i][1]);
    //         i++;
    //     }
    //     ans.push_back({ min_left, max_right });

    //     // 3rd case
    //     while (i < n) {
    //         ans.push_back(intervals[i]);
    //         i++;
    //     }

    //     return ans;
    // }
};