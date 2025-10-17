using PI2 = pair<int,int>;

// struct Compare {
//     bool operator()(PI2& a, PI2& b) const {
//         if (a.first == b.first) {
//             return a.second > b.second;
//         } else {
//             return a.first > b.first;
//         }
//     }
// };

struct Compare {
    bool operator()(const PI2& a, const PI2& b) const {
        if (a.first != b.first) return a.first > b.first;          // processingTime 小的優先
        return a.second > b.second;                                 // index 小的優先
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>> taskIndexes(n);
        for (int i = 0; i < n; i++) {
            taskIndexes[i][0] = tasks[i][0];
            taskIndexes[i][1] = tasks[i][1];
            taskIndexes[i][2] = i;
        }

        sort(taskIndexes.begin(), taskIndexes.end(), [](array<int,3>& a, array<int,3>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        priority_queue<PI2, vector<PI2>, Compare> pq; // processingTime, original index
        int i = 0;
        long long time = 0;
        vector<int> ans;

        while (i < n || !pq.empty()) {
            while (i < n && taskIndexes[i][0] <= time) {
                pq.push({ taskIndexes[i][1], taskIndexes[i][2] });
                i++;
            }
            if (pq.empty() && time < taskIndexes[i][0]) {
                time = taskIndexes[i][0];
                continue;
            }

            if (!pq.empty()) {
                auto [processingTime, originalIndex] = pq.top();
                time += processingTime;
                ans.push_back(originalIndex);
                pq.pop();
            }
        }        

        return ans;
    }
};