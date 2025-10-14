class ExamTracker {
public:
    vector<int> times{0};
    vector<long long> accScores{0};
    
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        times.push_back(time);
        accScores.push_back(score + accScores.back());
    }
    
    long long totalScore(int startTime, int endTime) {
        int n = times.size();
        int l = 0, r = n - 1;
        if (n == 0) return 0;
    
        // startTime: 找最後一個 < startTime 的 t
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (times[mid] < startTime) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int finalStart = r;

        // endTime: 找最後一個 <= endTime 的 t
        l = 0;
        r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (times[mid] <= endTime) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int finalEnd = r;
        return accScores[finalEnd] - accScores[finalStart];
    }
};

// class ExamTracker {
// public:
//     vector<int> times{0};
//     vector<long long> accScores{0};
    
//     ExamTracker() {
        
//     }
    
//     void record(int time, int score) {
//         times.push_back(time);
//         accScores.push_back(accScores.back() + score);
//     }
    
//     long long totalScore(int startTime, int endTime) {
//         // lo = 第一個 >= startTime 的索引
//         // hi = 第一個 >  endTime   的索引
//         int high = upper_bound(times.begin(), times.end(), endTime) - times.begin();
//         int low = lower_bound(times.begin(), times.end(), startTime) - times.begin();
//         return accScores[high - 1] - accScores[low - 1];
//     }
// };

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */