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

        sort(intervals.begin(), intervals.end(), [&](const vector<int> &iv1, const vector<int> &iv2) {
            return iv1[0] < iv2[0];
        });

        vector<vector<int>> ans;
        int currentL = intervals[0][0];
        int currentR = intervals[0][1];

        for (int i = 0; i < n; i++) {
            const auto& iv = intervals[i];
            if (iv[0] <= currentR) {
                currentR = max(currentR, iv[1]);
            } else {
                ans.push_back({ currentL, currentR });
                currentL = iv[0];
                currentR = iv[1];
            }
        }
        ans.push_back({ currentL, currentR });
        return ans;
    }

    // Approach: Line Sweep

    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     vector<pair<int,int>> events;
    //     for (auto& iv: intervals) {
    //         events.push_back({ iv[0], +1 });
    //         events.push_back({ iv[1], -1 });
    //     }
    //     sort(events.begin(), events.end(), [](const pair<int,int>& e1, const pair<int,int>& e2) {
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