class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<>> event_to_attend; // end

        int n = events.size();
        int day = 0;
        int event_idx = 0;
        int event_count = 0;

        while (event_idx < n || !event_to_attend.empty()) {
            if (event_to_attend.empty() && event_idx < n) {
                day = max(day, events[event_idx][0]);
            }
        
            // push in all available events
            while (event_idx < n && events[event_idx][0] <= day) {
                event_to_attend.push(events[event_idx][1]);
                event_idx++;
            }

            // remove the outdated events
            while (!event_to_attend.empty() && event_to_attend.top() < day) {
                event_to_attend.pop();
            }

            if (!event_to_attend.empty()) {
                event_to_attend.pop();
                event_count++;
            }

            day++;
        }

        return event_count;
    }
};

// test case: [[1,4],[4,4],[2,2],[3,4],[1,1]] -> 4
// events = [[1,1],[1,4],[2,2],[3,4],[4,4]]
//                       idx
// while loop
//  day = 1
//  event_to_attend = [1,4]
//  event_idx = 2
//  event_to_attend = [4]
//  event_count = 1
// 

// event_to_attend = [4]

// test case: events = [(1,2), (100,200)]
// trace:
// day = 1, last_day = 200
// day = 1
// event_to_attend = [2], event_idx = 1
// event_to_attend = [], event_count = 1
// day = 100
// event_to_attend = [200], event_idx = 2
// event_to_attend = [], event_count = 2
// 