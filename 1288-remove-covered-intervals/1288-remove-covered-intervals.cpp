class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
            if (i1[0] == i2[0]) return i1[1] > i2[1];
            return i1[0] < i2[0];
        });

        int n = intervals.size();
        int maxRight = -1;
        int remainingIntervals = n;

        for (int i = 0; i < n; i++) {
            if (maxRight >= intervals[i][1]) {
                remainingIntervals--;
            }
            maxRight = max(maxRight, intervals[i][1]);
        }
        return remainingIntervals;
    }

    // int removeCoveredIntervals(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
    //         if (i1[0] == i2[0]) return i1[1] > i2[1];
    //         return i1[0] < i2[0];
    //     });

    //     int remainingIntervals = 0;
    //     int maxRight = intervals[0][0];
    //     for (auto& interval: intervals) {
    //         if (interval[1] > maxRight) {
    //             remainingIntervals++;
    //             maxRight = interval[1];
    //         }
    //     }
    //     return remainingIntervals;
    // }
};