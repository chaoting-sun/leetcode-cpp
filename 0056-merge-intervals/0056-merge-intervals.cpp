class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n == 0) return intervals;

        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        int min_left = intervals[0][0];
        int max_right = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (max_right >= intervals[i][0]) {
                max_right = max(max_right, intervals[i][1]);
            } else {
                ans.push_back({ min_left, max_right });
                min_left = intervals[i][0];
                max_right = intervals[i][1];
            }
        }
        ans.push_back({ min_left, max_right });

        return ans;
    }
};