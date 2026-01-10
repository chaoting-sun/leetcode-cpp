// O(n)

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         if (n == 0) return 0;
        
//         vector<int> left_smaller_idx(n, -1);
//         vector<int> right_smaller_idx(n, n);
//         stack<int> stk;

//         for (int i = 0; i < n; i++) {
//             while (!stk.empty() && heights[stk.top()] >= heights[i]) {
//                 stk.pop();
//             }
//             if (!stk.empty()) left_smaller_idx[i] = stk.top();
//             stk.push(i);
//         }

//         while (!stk.empty()) stk.pop();

//         for (int i = n - 1; i >= 0; i--) {
//             while (!stk.empty() && heights[i] <= heights[stk.top()]) {
//                 stk.pop();
//             }
//             if (!stk.empty()) right_smaller_idx[i] = stk.top();
//             stk.push(i);
//         }

//         int max_area = 0;
//         for (int i = 0; i < n; i++) {
//             int current_area = heights[i] * (right_smaller_idx[i] - left_smaller_idx[i] - 1);
//             max_area = max(max_area, current_area);
//         }

//         return max_area;
//     }
// };

// O(1)

// strictly increasing monotonic stack

// [1(2) 3(5) 4(10)] heights[i] = 3
// stk.top() -> h = 10, w = i - 上一個 index - 1

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        int max_area = 0;
        stack<int> stk;

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int left_min = stk.empty() ? -1 : stk.top();
                int current_width = i - left_min - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }

        return max_area;
    }
};