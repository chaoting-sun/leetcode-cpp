class Solution {
public:
    // Approach: sort the intervals based on their first value. Then, we take the first interval
    // and compare its end with the next intervals start to check if they overlap. if they overlap
    // we extend the max end of the merged interval and looking the next one.
    // Time: O(nlogn)
    // Space: O(1)

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n == 0) return intervals;

        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        int left = -1;
        int maxRight = INT_MIN;
        for (auto& iv: intervals) {
            if (maxRight < iv[0]) {
                if (maxRight != INT_MIN) {
                    ans.push_back({ left, maxRight });
                }
                left = iv[0];
            }
            maxRight = max(maxRight, iv[1]);
        }
        ans.push_back({ left, maxRight });

        return ans;
    }

    // Approach: Line Sweep

    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     vector<pair<int,int>> events;
    //     for (auto& iv: intervals) {
    //         events.push_back({ iv[0], +1 });
    //         events.push_back({ iv[1], -1 });
    //     }
    //     sort(events.begin(), events.end(), [](pair<int,int>& e1, pair<int,int>& e2) {
    //         if (e1.first == e2.first) return e1.second > e2.second;
    //         return e1.first < e2.first;
    //     });

    //     int count = 0;
    //     int start = 0;
    //     vector<vector<int>> ans;
    //     for (auto [pos, e]: events) {
    //         count += e;
    //         // We just opened a new merged interval
    //         if (count == 1 && e == 1) {
    //             start = pos;
    //         }
    //         // We just closed the merged interval
    //         if (count == 0) {
    //             ans.push_back({ start, pos });
    //         }
    //     }
    //     return ans;
    // }
};