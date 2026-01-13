class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> event_to_attend; // end, idx

        int min_day = INT_MAX, max_day = INT_MIN;
        for (int i = 0; i < events.size(); i++) {
            min_day = min(min_day, events[i][0]);
            max_day = max(max_day, events[i][1]);
        }

        int event_idx = 0;
        int min_events = 0;
        for (int i = min_day; i <= max_day; i++) {
            // pop out all expired events
            while (!event_to_attend.empty() && event_to_attend.top().first < i) {
                event_to_attend.pop();
            }
            // push in all available events
            while (event_idx < events.size() && events[event_idx][0] <= i) {
                event_to_attend.push({ events[event_idx][1], event_idx });
                event_idx++;
            }
            if (!event_to_attend.empty()) {
                min_events++;
                event_to_attend.pop();
            }
        }

        return min_events;
    }
};

// test case: [2,2], [2,3], [2,3]
// trace:
// min_day = 2, max_day = 3
// for loop: i = 2,3
// i = 2
// event_to_attend = [{ 2, 0 }], event_idx = 1
// event_to_attend = [{ 2, 0 }, { 3, 1 }], event_idx = 2
// event_to_attend = [{ 2, 0 }, { 3, 1 }, { 3, 2 }], event_idx = 3
// min_events = 1, event_to_attend = [{ 3, 1 }, { 3, 2 }]
// i = 3
// min_events = 2, event_to_attend = [{ 3, 2 }]

// test case: [1,2], [2,3], [3,4]
// trace:
// min_day = 1, max_day = 4
// for loop, i = 1,2,3,4
// i = 1
// event_to_attend = [{ 2, 0 }] -> min_events = 1, event_to_attend = []
// i = 2
// event_to_attend = [{ 3, 1 }] -> min_events = 2, event_to_attend = []
// i = 3
// event_to_attend = [{ 4, 2 }] -> min_events = 3, event_to_attend = []