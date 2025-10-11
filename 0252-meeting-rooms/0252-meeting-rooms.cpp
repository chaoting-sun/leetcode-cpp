class Solution {
public:
    // Approach: sort the intervals by the start time. loop the intervals one by one, comparing
    // the ith end time (A) and (i+1)th start time (B). if any A > B this means the two meeting
    // has overlapped time.

    // Time: O(nlogn) for sorting
    // Space: O(1)

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return true;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        for (int i = 0; i < n - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }

    // bool canAttendMeetings(vector<vector<int>>& intervals) {
    // }
};