class MyCalendarThree {
public:
    map<int, int> events;

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;
        int maxEvents = 0, currentEvents = 0;
        for (auto& [e, n]: events) {
            currentEvents += n;
            maxEvents = max(maxEvents, currentEvents);
        }
        return maxEvents;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */