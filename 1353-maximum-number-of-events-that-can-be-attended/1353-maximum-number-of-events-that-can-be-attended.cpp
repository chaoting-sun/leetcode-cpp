class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<>> event_to_attend; // end

        int day = events.front()[0], last_day = 1e5;
        int event_idx = 0;
        int event_count = 0;

        while (day <= last_day) {
            // push in all available events
            while (event_idx < events.size() && events[event_idx][0] <= day) {
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
            
            // day
            if (event_to_attend.empty() && event_idx < events.size()) {
                day = events[event_idx][0];
            } else if (event_to_attend.empty() && event_idx == events.size()) {
                break;
            } else {
                day++;
            }
        }

        return event_count;
    }
};

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