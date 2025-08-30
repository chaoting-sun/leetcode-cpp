class Solution {
public:
    // Approach: sort the intervals array, comparing the start position.
    // then we loop through the array. for each interval we compare it with the next one. if they
    // overlap, then we remove the one with larger end position as it has the higher chance to overlap
    // with the next ones. if they do not overlap, then we move to the next one.
    
    // Time: O(nlogn)
    // Space: O(1)
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return 0;

        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int n_remove = 0;
        int i = 0; // the one to compare
        int j = 1; // the one to be compared with

        while (i < n - 1 && j < n) {
            // do not overlap
            if (intervals[i][1] <= intervals[j][0]) {
                i = j;
                j = i + 1;
                continue;
            }

            // the ith end position is larger then the jth end position
            if (intervals[i][1] > intervals[j][1]) {
                // remove ith interval
                n_remove++;
                i = j;
                j = i + 1;
            } else {
                // remove jth interval
                n_remove++;
                j++;
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
