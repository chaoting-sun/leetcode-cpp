// Approach: Line Sweep
// Time: O(nlogn)
// Space: O(n)

// class MyCalendar {
// public:
//     map<int,int> events;

//     MyCalendar() {
        
//     }
    
//     bool book(int startTime, int endTime) {
//         events[startTime]++;
//         events[endTime]--;
//         int eventCount = 0;
//         for (auto& [t, e]: events) {
//             eventCount += e;
//             if (eventCount > 1) {
//                 events[startTime]--;
//                 events[endTime]++;
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// Approach: Set
// Time: O(nlogn)
// Space: O(n)

class MyCalendar {
public:
    set<pair<int,int>> calendar;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        pair<int,int> booking = { startTime, endTime };
        // find the first existing booking with s1 >= startTime or e1 >= endTime
        auto nextEvent = calendar.lower_bound(booking);
        if (nextEvent != calendar.end() && nextEvent->first < endTime) {
            return false;
        }
        if (nextEvent != calendar.begin()) {
            auto prevEvent = prev(nextEvent);
            if (startTime < prevEvent->second) {
                return false;
            }
        }
        calendar.insert(booking);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */