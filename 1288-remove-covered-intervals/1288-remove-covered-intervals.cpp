class Solution {
public:
    // int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
        //     if (i1[0] == i2[0]) return i1[1] > i2[1];
        //     return i1[0] < i2[0];
        // });

    //     int n = intervals.size();
    //     int maxRight = intervals[0][1];
    //     int remainingIntervals = n;

    //     for (int i = 0; i < n - 1; i++) {
    //         maxRight = max(maxRight, intervals[i][1]);
    //         if (maxRight >= intervals[i + 1][1]) {
    //             remainingIntervals--;
    //         }
    //     }
    //     return remainingIntervals;
    // }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
            if (i1[0] == i2[0]) return i1[1] > i2[1];
            return i1[0] < i2[0];
        });

        int remainingIntervals = 0;
        int maxRight = intervals[0][0];
        for (auto& interval: intervals) {
            if (interval[1] > maxRight) {
                remainingIntervals++;
                maxRight = interval[1];
            }
        }
        return remainingIntervals;
    }
};

// [[1,2],[1,4],[3,4]]