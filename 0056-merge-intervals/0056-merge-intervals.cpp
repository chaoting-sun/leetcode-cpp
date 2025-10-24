class Solution {
public:
    // Approach: sort the intervals based on their first value. Then, we take the first interval
    // and compare its end with the next intervals start to check if they overlap. if they overlap
    // we extend the max end of the merged interval and looking the next one.
    // Time: O(nlogn)
    // Space: O(1)

    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     int n = intervals.size();

    //     if (n == 0) return intervals;

    //     sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b) {
    //         return a[0] < b[0];
    //     });

    //     vector<vector<int>> ans;
    //     int min_left = intervals[0][0];
    //     int max_right = intervals[0][1];

    //     for (int i = 1; i < n; i++) {
    //         if (max_right >= intervals[i][0]) {
    //             max_right = max(max_right, intervals[i][1]);
    //         } else {
    //             ans.push_back({ min_left, max_right });
    //             min_left = intervals[i][0];
    //             max_right = intervals[i][1];
    //         }
    //     }
    //     ans.push_back({ min_left, max_right });

    //     return ans;
    // }

    // Approach: Line Sweep

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> events;
        for (auto& iv: intervals) {
            events.push_back({ iv[0], +1 });
            events.push_back({ iv[1], -1 });
        }
        sort(events.begin(), events.end(), [](pair<int,int>& e1, pair<int,int>& e2) {
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });

        int count = 0;
        int start = 0;
        vector<vector<int>> ans;
        for (auto [pos, e]: events) {
            count += e;
            // We just opened a new merged interval
            if (count == 1 && e == 1) {
                start = pos;
            }
            // We just closed the merged interval
            if (count == 0) {
                ans.push_back({ start, pos });
            }
        }
        if (count != 0) {
            ans.push_back({ start, events.back().first });
        }
        return ans;
    }
};

// 1 2 3 4 5 6 7 8
// 1       -1
//         1  -1

// 1 1 1 1 1 1 1 0