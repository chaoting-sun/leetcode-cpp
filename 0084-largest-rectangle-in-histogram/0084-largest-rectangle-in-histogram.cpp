class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> leftLower(n, -1), rightLower(n, n);
        stack<int> stk; // monotonic strictly increasing stack; store index
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (!stk.empty()) leftLower[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) rightLower[i] = stk.top();
            stk.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, (rightLower[i] - leftLower[i] - 1) * heights[i]);
        }
        return maxArea;
    }
};

// []
// [1]
// [3, 1]

// 某個高度底下可以到多寬
// 假想在某個 bar 的高為高度的前提下，矩形左右可以到多寬
// 最大的矩形一定是最高處與某個 bar 一樣高

// 對每個矩形，往左右兩邊找到比他矮的前一格
// 先找左邊，比當前矩形還要小的人
// 想找不到的情況 -> 左邊的人都比他高
// 應該是用 monotonic stack 只是應該是用 decreasing 還是 increasing

// monotonic strictly increasing stack
// area = heights[i] * (r - l - 1)