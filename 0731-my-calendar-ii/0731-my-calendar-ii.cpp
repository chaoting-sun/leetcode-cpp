class MyCalendarTwo {
public:
    map<int,int> events;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;
        int eventCount = 0;
        for (auto& [t, e]: events) {
            eventCount += e;
            if (eventCount > 2) {
                events[startTime]--;
                events[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */