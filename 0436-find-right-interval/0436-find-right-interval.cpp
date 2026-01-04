class Solution {
private:
    struct Interval {
        int idx;
        int start;
        int end;
    };

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int length = intervals.size();
        
        vector<Interval> sorted_intervals;
        sorted_intervals.reserve(length);

        for (int i = 0; i < intervals.size(); i++) {
            sorted_intervals.push_back({ i, intervals[i][0], intervals[i][1] });
        }
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](Interval i1, Interval i2) {
            return i1.start < i2.start;
        });

        vector<int> ans(length, -1);

        for (int i = 0; i < length; i++) {
            Interval curr = sorted_intervals[i];
            if (curr.start == curr.end) {
                ans[curr.idx] = curr.idx;
                continue;
            }

            // binary search: find the first start that is larger or equal to the target
            int target = curr.end;
            int left = 0;
            int right = length;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sorted_intervals[mid].start >= target) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (right >= 0 && right < length) {
                ans[curr.idx] = sorted_intervals[right].idx;
            }
        }

        return ans;
    }
};

// CE
// struct 後面沒加 ;

// test case: intervals = [[1,1], [3,4], [2,3]] -> [0, -1, 2]
// 包含 right interval 是自己的區間, 有 right interval 的區間, 沒有 right interval 的區間
// trace:
// results = [[0,-1],[1,-1],[2,-1]]
// sort -> results = [[0,-1],[2,-1],[1,-1]]
// sort -> intervals = [[1,1], [2,3], [3,4]]
// i = 0
//  results = [[0,0],[2,-1],[1,-1]]
// i = 1 -> [2,3]
//  target = 3, left = 0, right = 3
//  mid = 1 -> left = 2
//  mid = 2 -> right = 2
//  break
//  results = [[0,0],[2,2],[1,-1]]
// i = 2 -> [3,4]
//  target = 4, left = 0, right = 3
//  mid = 1 -> left = 2
//  mid = 2 -> left = 3
//  break;
//  results = [[0,0],[2,2],[1,-1]]
// sort -> results = [[0,0],[1,-1],[2,2]]
// < returns ans = [0, -1, 2]

// Submit Error:
// results[i] = i; -> results[i].second = i;