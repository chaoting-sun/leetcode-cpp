class Solution {
public:
    // Approach: priority queue (min heap)
    // push the meeting time into the min heap (by end time) in the order of start time.
    // so the top of the min heap will be the meeting that ends first.
    // if we find a meeting that has end time <= the start time of the current meeting,
    // then the current meeting can use the room of it.

    // Time: O(nlogn) -> sorting and push/pop of min heap
    // Space: O(n)

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<>> pq; // minheap
        int maxRooms = 0;
        for (auto& interval: intervals) {
            while (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
            maxRooms = max(maxRooms, (int)pq.size());
        }
        return maxRooms;
    }

    // Approach: Chronological ordering
    // Time: O(nlogn)
    // Space: O(n)

    // int minMeetingRooms(vector<vector<int>>& intervals) {
    //     int n = intervals.size();
    //     if (n <= 1) return n;

    //     vector<int> start_times(n), end_times(n);
    //     for (int i = 0; i < n; i++) {
    //         start_times[i] = intervals[i][0];
    //         end_times[i] = intervals[i][1];
    //     }

    //     sort(start_times.begin(), start_times.end());
    //     sort(end_times.begin(), end_times.end());

    //     int rooms = 0;
    //     int i = 0, j = 0;

    //     while (i < n) {
    //         // the meeting of earliest end time has not finished, so we need to increase a room
    //         if (start_times[i] < end_times[j]) {
    //             rooms++;
    //             i++;
    //         } 
    //         // there is a meeting ended. a previously used room is empty now, so we can use it for the current meeting
    //         else {
    //             i++;
    //             j++;
    //         }
    //     }

    //     return rooms;
    // }

    // For practice

    // int minMeetingRooms(vector<vector<int>>& intervals) {
    // }
};

// [(0,1)] -> 1
// [(0,2),(1,3)] -> 2
// [(0,2),(2,4)] -> 1