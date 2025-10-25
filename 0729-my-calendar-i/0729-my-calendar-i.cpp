class MyCalendar {
public:
    map<int,int> events;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;
        int eventCount = 0;
        for (auto& [t, e]: events) {
            eventCount += e;
            if (eventCount > 1) {
                events[startTime]--;
                events[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */