class Solution {
public:
    // Approach: Sort + Heap
    // Time: O(nlogn)
    // Space: O(n)

    // int minGroups(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end());
    //     priority_queue<int, vector<int>, greater<>> pq;
    //     for (auto& interval: intervals) {
    //         if (!pq.empty() && pq.top() < interval[0]) {
    //             pq.pop();
    //             pq.push(interval[1]);
    //         } else {
    //             pq.push(interval[1]);
    //         }
    //     }
    //     return pq.size();
    // }

    // Approach: Line Sweep -> We find where most intervals intersect with each other
    // Time: O(nlogn)
    // Space: O(n)

    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> intervalCounts;
        for (auto& interval: intervals) {
            intervalCounts[interval[0]]++;
            intervalCounts[interval[1] + 1]--;
        }
        int currentCount = 0, maxCount = 0;
        for (auto [_, cnt]: intervalCounts) {
            currentCount += cnt;
            maxCount = max(maxCount, currentCount);
        }
        return maxCount;
    }
};
