class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<>> pq;
        for (auto& interval: intervals) {
            if (!pq.empty() && pq.top() < interval[0]) {
                pq.pop();
                pq.push(interval[1]);
            } else {
                pq.push(interval[1]);
            }
        }
        return pq.size();
    }
};
