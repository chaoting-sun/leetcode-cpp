// ## Understand

// What is the range of n? -> 1 <= n <= 10^4
// What is the length of ranges? -> n + 1
// What is the range of each element in ranges? 0 <= ranges[i] <= 100


// ## Match

// A bruteforce method I come up with is to try every combination of the intervals. Each
// combination can include or not include range i. The answer will be the smallest number
// of taps that covers the whole garden.

// As the range is defined in a dimension that has two endpoints, we can map this problem
// as an interval problem. A common preprocessing in the interval problem is to sort the
// intervals. This may help us to easily cover the garden in some kind of order.

// ## Plan

// Me:
// The method I come up with will be, we sort the intervals by the start of the interval,
// and then the end of the interval. We firstly search for the first interval that covers
// 0, then try to add new intervals that helps extend the most covered area.


// Interviewer:
// Question: Can you explicitly define how you will transform the ranges array into the
// intervals you plan to sort? Be careful about the boundaries (e.g., < 0 or > n).
// Question: Let's say you have currently covered the garden from 0 to current_end.
// You have a list of remaining sorted intervals.
// Which specific intervals are valid candidates to pick next?
// Among those candidates, which one is the "best"?

// Me:
// I will transform ranges to intervals using the math [i - ranges[i], i + ranges[i]], and
// sort the intervals by the start. suppose that we currently covered the garden from 0
// to current_end, to minimize the taps, we need to find the intervals that extends the current_end
// to the largest right. Specifically, I will use a max heap that sort by the end point.
// Every time, I push the those intervals with the start point less or equal to the current_end
// to the max heap. The best next interval to extend the area will be on the top.
// as the intervals has been sorted, we can just iterate through the intervals to decide
// which to push to the max heap.

// Interviewer:
// 1. Optimization: Is the Heap necessary?
// You proposed using a Max Heap to find the interval with the largest right endpoint.
// - Observation: Since you are already iterating through the sorted intervals, you will process
// all valid candidates (starts $\le$ current_end) in a contiguous batch.
// - Question: Instead of maintaining a heap (which adds $O(\log N)$ overhead for insertions),
// could you simply track a single variable, say farthest_reach, while iterating through that batch?
// 2. Handling the "Impossible" Case (-1)
// You haven't explicitly defined the failure condition yet.
// * Question: Using your logic, how specifically will you detect if there is a gap that prevents you
// from reaching n? (e.g., what happens if you exhaust all intervals starting $\le$ current_end,
// but your farthest_reach hasn't extended past current_end?)
// Action:
// Could you verify your logic by dry running it on Example 1 (mentally or written out) without the heap,
// using just a farthest_reach variable? This will confirm if the logic holds.
// Example 1:
// n = 5
// ranges = [3,4,1,1,0,0]
// 1. Transform & Sort: (List out the intervals roughly)
// 2. Iterate: Track current_end (starts at 0) and farthest_reach.
// Walk me through this trace.

// Me:
// I will iterate through the sorted intervals while maintaining a variable farthest_right initialized to 0.
// To minimize the number of intervals, I search for all intervals with start less or equal to the farthest_right
// and find the maximum right among them. Then, I update the total number of used intervals and set the maximum right
// as the farthest_right.
// If we cannot extend the farthest_right to the n, then it is impossible to cover the whole garden. we return -1.


// Implementation

// class Solution {
// private:
//     struct Interval {
//         int start;
//         int end;
//     };

// public:
//     int minTaps(int n, vector<int>& ranges) {
//         // create intervals from ranges
//         vector<Interval> intervals;
//         for (int i = 0; i <= n; i++) {
//             intervals.push_back({ i - ranges[i], i + ranges[i] });
//         }

//         // sort the intervals first such that we can merge the intervals in one iteration
//         sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
//             return a.start < b.start;
//         });

//         // use farthest_right to track the current covered range
//         int farthest_right = 0;
//         int idx = 0;
//         int tap_count = 0;

//         while (idx < intervals.size()) {
//             int curr_idx = idx;
//             int current_farthest_right = farthest_right;
//             // each time, I search for all intervals overlapped with the currently covered range
//             while (curr_idx < intervals.size() && intervals[curr_idx].start <= farthest_right) {
//                 current_farthest_right = max(current_farthest_right, intervals[curr_idx].end);
//                 curr_idx++;
//             }

//             // if there is no interval that can extend the covered range
//             // then we stop the merging process
//             if (current_farthest_right == farthest_right) {
//                 break;
//             }

//             tap_count++;
//             farthest_right = current_farthest_right;

//             idx = curr_idx;
//         }
        
//         // if the final merged range can cover up to n, then return the tap count.
//         return farthest_right >= n ? tap_count : -1;
//     }
// };


// ## Review
// test: n = 1, ranges = [0] -> -1
// trace:
// intervals = [(0,0)]
// idx = 0, interval size = 1
// while loop: curr_idx = 0, current_farthest_right = 0
// < returns -1

// test: n = 2, ranges = [0,1,1] -> 1 tap
// 0 ---- 1 ---- 2 ---- 3
// 0
//  ------------
//        -------------
// trace:
// intervals = [(0,0), (0,2), (1,3)]
// sort -> intervals = [(0,0), (0,2), (1,3)]
// idx = 0, interval size = 3
// while loop: curr_idx = 2, current_farthest_right = 2
// tap_count = 1
// farthest_right = 2
// idx = 3
// < returns 2


// ## Evaluation

// Time: O(nlogn). the time complexity is decided by the sort of the intervals
// Space: O(n). we need to create intervals for merging


// ## Submit Error

// RE:
// while (curr_idx < intervals.size() && intervals[curr_idx].start <= farthest_right) {
//     curr_idx++;
//     current_farthest_right = max(current_farthest_right, intervals[curr_idx].end);
// }
// to
// while (curr_idx < intervals.size() && intervals[curr_idx].start <= farthest_right) {
//     current_farthest_right = max(current_farthest_right, intervals[curr_idx].end);
//     curr_idx++;
// }

// WA: n = 8, ranges = [4,0,0,0,4,0,0,0,4]

// updated version

class Solution {
private:
    struct Interval {
        int start;
        int end;
    };

public:
    int minTaps(int n, vector<int>& ranges) {
        // create intervals from ranges
        vector<Interval> intervals;
        for (int i = 0; i <= n; i++) {
            intervals.push_back({ i - ranges[i], i + ranges[i] });
        }

        // sort the intervals first such that we can merge the intervals in one iteration
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });

        // use farthest_right to track the current covered range
        int farthest_right = 0;
        int idx = 0;
        int tap_count = 0;

        while (idx < intervals.size() && farthest_right < n) {
            int curr_idx = idx;
            int current_farthest_right = farthest_right;
            // each time, I search for all intervals overlapped with the currently covered range
            while (curr_idx < intervals.size() && intervals[curr_idx].start <= farthest_right) {
                current_farthest_right = max(current_farthest_right, intervals[curr_idx].end);
                curr_idx++;
            }

            // if there is no interval that can extend the covered range
            // then we stop the merging process
            if (current_farthest_right == farthest_right) {
                break;
            }

            tap_count++;
            farthest_right = current_farthest_right;

            idx = curr_idx;
        }
        
        // if the final merged range can cover up to n, then return the tap count.
        return farthest_right >= n ? tap_count : -1;
    }
};
