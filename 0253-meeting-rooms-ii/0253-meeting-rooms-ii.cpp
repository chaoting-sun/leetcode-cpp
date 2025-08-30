struct Compare {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
        return a[1] > b[1];
    }
};

class Solution {
public:
    // Approach: priority queue (min heap)
    // push the meeting time into the min heap (by end time) in the order of start time.
    // so the top of the min heap will be the meeting that ends first.
    // if we find a meeting that has end time <= the start time of the current meeting,
    // then the current meeting can use the room of it.

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return n;

        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        int rooms = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (pq.empty() || pq.top()[1] > intervals[i][0]) {
                pq.push(intervals[i]);
                rooms = max(rooms, static_cast<int>(pq.size()));
            } else {
                pq.pop();
                pq.push(intervals[i]);
            }
        }

        return rooms;
    }
};

// [[0,30],[5,10],[15,20]]