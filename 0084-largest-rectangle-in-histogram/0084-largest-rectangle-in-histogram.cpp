class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        
        vector<int> left_smaller_idx(n, -1);
        vector<int> right_smaller_idx(n, n);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (!stk.empty()) left_smaller_idx[i] = stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) right_smaller_idx[i] = stk.top();
            stk.push(i);
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int current_area = heights[i] * (right_smaller_idx[i] - left_smaller_idx[i] - 1);
            max_area = max(max_area, current_area);
        }

        return max_area;
    }
};