class Solution {
public:
    // Approach:
    // Greedy: sort by end time; always keep the interval that ends earliest.
    // That choice leaves maximum room for future intervals, minimizing removals.
    
    // Time: O(nlogn)
    // Space: O(1)
    
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     int n = intervals.size();
    //     if (n == 1) return 0;

    //     sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
    //         return a[0] < b[0];
    //     });

    //     int n_remove = 0;
    //     int i = 0; // the one to compare
    //     int j = 1; // the one to be compared with

    //     while (i < n - 1 && j < n) {
    //         // do not overlap
    //         if (intervals[i][1] <= intervals[j][0]) {
    //             i = j;
    //             j = i + 1;
    //             continue;
    //         }

    //         // the ith end position is larger then the jth end position
    //         if (intervals[i][1] > intervals[j][1]) {
    //             // remove ith interval
    //             n_remove++;
    //             i = j;
    //             j = i + 1;
    //         } else {
    //             // remove jth interval
    //             n_remove++;
    //             j++;
    //         }
    //     }

    //     return n_remove;
    // }

    // Optimized Approach: The original approach keep track of which two to compare,
    // but we can just keep maintaining the current end position and use it to compare
    // with that of the new intervals coming in. As they have already sorted by start
    // position, we can just check the end position to check for overlapping.

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return 0;

        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int curr_end = intervals[0][1];
        int n_remove = 0;
        for (int i = 1; i < n; i++) {
            // overlap
            if (curr_end > intervals[i][0]) {
                n_remove++;
                curr_end = min(curr_end, intervals[i][1]);
            } else {
                curr_end = intervals[i][1];
            }
        }

        return n_remove;

    }
};

// [[1,4], [2,5], [3,6], [6,10]] -> n = 4
// i = 0, j = 1
// n_remove = 1, j = 2
// n_remove = 2, j = 3
// i = 3, j = 4
