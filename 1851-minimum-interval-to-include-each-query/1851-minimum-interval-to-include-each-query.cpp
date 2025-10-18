// Approach:
// Sort intervals by start and queries ascending. Maintain a min-heap of (length, end).
// For each query q (in ascending order), push all intervals with start ≤ q.
// Then pop any with end < q. The heap now contains exactly the intervals that cover q,
// and the top has the minimum length. If the heap is empty, answer is -1.
// Because both are sorted, any interval that can cover the next query will either
// already be in the heap or will appear among the remaining intervals.

// Time:
//  - n log n -> sort interval; push/pop the intervals in pq
//  - q log q -> sort the queries
// Space: O(n + q)

// struct Compare {
//     bool operator()(pair<int,int> &a, pair<int,int> &b) const {
//         return a.first > b.first;
//     }
// };

// class Solution {
// public:
//     vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
//         int ni = intervals.size(), nq = queries.size();
        
//         sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
//             return a[0] < b[0];
//         });

//         vector<int> sorted_queries = queries;
//         sort(sorted_queries.begin(), sorted_queries.end());
//         priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq; // size, interval end

//         int j = 0;
//         unordered_map<int, int> query_ans;

//         for (int i = 0; i < nq; i++) {
//             int q = sorted_queries[i];
//             while (j < ni && intervals[j][0] <= q) {
//                 pq.push({ intervals[j][1] - intervals[j][0] + 1, intervals[j][1] });
//                 j++;
//             }

//             while (!pq.empty() && pq.top().second < q) {
//                 pq.pop();
//             }

//             query_ans[q] = pq.empty() ? -1 : pq.top().first;
//         }

//         vector<int> ans(nq);
//         for (int i = 0; i < nq; i++) {
//             ans[i] = query_ans[queries[i]];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int nq = queries.size();
        vector<pair<int,int>> sortedQueries(nq);
        for (int i = 0; i < nq; i++) {
            sortedQueries[i] = { queries[i], i };
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int intervalIdx = 0;        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans(nq, -1);
        for (auto [q, i]: sortedQueries) {
            while (intervalIdx < n && intervals[intervalIdx][0] <= q) {
                pq.push({ intervals[intervalIdx][1] - intervals[intervalIdx][0] + 1, intervals[intervalIdx][1] });
                intervalIdx++;
            }
            while (!pq.empty() && pq.top().second < q) pq.pop();
            if (!pq.empty()) ans[i] = pq.top().first;
        }
        return ans;
    }
};
