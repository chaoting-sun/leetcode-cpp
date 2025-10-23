class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
            if (i1[0] == i2[0]) return i1[1] > i2[1];
            return i1[0] < i2[0];
        });

        int n = intervals.size();
        int maxRight = intervals[0][1];
        int remainingIntervals = n;
        vector<bool> isRemoved(n, false);

        for (int i = 0; i < n - 1; i++) {
            maxRight = max(maxRight, intervals[i][1]);
            if (maxRight >= intervals[i + 1][1]) {
                remainingIntervals--;
                isRemoved[i + 1] = true;
                if (intervals[i][0] == intervals[i + 1][0] && intervals[i][1] == intervals[i + 1][1] && !isRemoved[i]) {
                    remainingIntervals--;
                    isRemoved[i] = true;
                }
            }
        }
        return remainingIntervals;
    }
};

// [[1,2],[1,4],[3,4]]