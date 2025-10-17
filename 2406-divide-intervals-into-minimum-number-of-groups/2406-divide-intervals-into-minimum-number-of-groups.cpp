class Solution {
public:
    // Approach: Sort + Heap
    // Time: O(nlogn)
    // Space: O(n)

    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
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
