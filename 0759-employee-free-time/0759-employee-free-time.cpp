/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

// [1,2], [3,4]
// [1: +1, 2:-1 3:+1, 5:-1]
// 1: +1, 2:0, 3: +1

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int,int> workingEvents;
        for (auto& s: schedule) {
            for (auto& e: s) {
                workingEvents[e.start]++;
                workingEvents[e.end]--;
            }
        }
        vector<Interval> ans;
        int current = 0;
        int freeTimeStart = -1;
        for (auto [t, cnt]: workingEvents) {
            current += cnt;
            if (current == 0) {
                freeTimeStart = t;
            } else {
                if (freeTimeStart != -1) {
                    ans.push_back(Interval(freeTimeStart, t));
                    freeTimeStart = -1;
                }
            }
        }
        return ans;
    }
};