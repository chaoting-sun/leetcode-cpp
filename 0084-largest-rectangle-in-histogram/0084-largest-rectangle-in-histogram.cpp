class Solution {
public:
    // Approach1: brute-force
    // Time: O(n^3), n is the length of heights
    // Space: O(1)

    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     int ans = 0;

    //     for (int i = 0; i < n; i++) {
    //         for (int j = i; j < n; j++) {
    //             int min_height = INT_MAX;
    //             for (int k = i; k <= j; k++) min_height = min(min_height, heights[k]);
    //             ans = max(ans, min_height * (j - i + 1));
    //         }
    //     }
    //     return ans;
    // }

    // Approach1.1: better brute-force
    // Time: O(n^2)
    // Space: O(1)

    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     int ans = 0;

    //     for (int i = 0; i < n; i++) {
    //         int min_height = INT_MAX;
    //         for (int j = i; j < n; j++) {
    //             min_height = min(min_height, heights[j]);
    //             ans = max(ans, min_height * (j - i + 1));
    //         }
    //     }
    //     return ans;
    // }

    // Intuition: Divide and Conquer. We observe that the maximum area is the maximum of the:
    // 1. The widest possible rectangle with height equal to the height of the shortest bar.
    // 2. The largest rectangle confined to the left of the shortest bar(subproblem).
    // 3. The largest rectangle confined to the right of the shortest bar(subproblem).
    // Approach: Divide and Conquer
    // Time: O(n*log(n)) in average case. but O(n^2) if heights is sorted
    // Space: O(1)

    // int divide_and_conquer(vector<int>& heights, int start, int end) {
    //     if (start > end) return -1;

    //     int min_id = start;
    //     for (int i = start; i <= end; i++) {
    //         if (heights[i] < heights[min_id]) min_id = i;
    //     }

    //     int max_area_left = divide_and_conquer(heights, start, min_id - 1);
    //     int max_area_right = divide_and_conquer(heights, min_id + 1, end);
    //     int max_area_center = (end - start + 1) * heights[min_id];
    //     return max(max(max_area_left, max_area_right), max_area_center);
    // }

    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     return divide_and_conquer(heights, 0, n - 1);
    // }

    // Intuition: Monotonic Stack
    // Time: O(n)
    // Space: O(n)

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;

        vector<int> nextSmaller(n, n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                nextSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        vector<int> prevSmaller(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                prevSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        for (int i = 0; i < n; i++) cout << nextSmaller[i] << " ";
        for (int i = 0; i < n; i++) cout << prevSmaller[i] << " ";

        int max_area = -1;

        for (int i = 0; i < n; i++) {
            int area = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
            max_area = max(max_area, area);
        }

        return max_area;
    }
};