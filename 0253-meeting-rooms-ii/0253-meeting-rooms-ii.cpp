// Approach: priority queue (min heap)
// push the meeting time into the min heap (by end time) in the order of start time.
// so the top of the min heap will be the meeting that ends first.
// if we find a meeting that has end time <= the start time of the current meeting,
// then the current meeting can use the room of it.

// Time: O(nlogn) -> sorting and push/pop of min heap
// Space: O(n)

// class Solution {
// public:
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
//             return a[0] < b[0];
//         });
//         priority_queue<int, vector<int>, greater<>> pq; // minheap
//         int maxRooms = 0;
//         for (auto& interval: intervals) {
//             while (!pq.empty() && pq.top() <= interval[0]) {
//                 pq.pop();
//             }
//             pq.push(interval[1]);
//             maxRooms = max(maxRooms, (int)pq.size());
//         }
//         return maxRooms;
//     }
// };

struct MeetingEvent {
    int time;
    bool isStartTime;
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<MeetingEvent> meetingEvents;
        for (int i = 0; i < n; i++) {
            meetingEvents.push_back({ intervals[i][0], true });
            meetingEvents.push_back({ intervals[i][1], false });
        }
        sort(meetingEvents.begin(), meetingEvents.end(), [](MeetingEvent& e1, MeetingEvent& e2) {
            if (e1.time != e2.time) return e1.time < e2.time;
            return !e1.isStartTime;
        });
        int maxRooms = 0, currentRooms = 0;
        for (MeetingEvent& e: meetingEvents) {
            currentRooms += e.isStartTime ? 1 : -1;
            maxRooms = max(maxRooms, currentRooms);
        }
        return maxRooms;
    }
};