class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n);
        int max_area = 0;

        for (int i = 0; i < m; i++) {
            // update heights
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }

            stack<int> stk;
            for (int j = 0; j <= n; j++) {
                int next_height = (j == n ? 0 : heights[j]); // 0
                while (!stk.empty() && heights[stk.top()] >= next_height) {
                    int current_height = heights[stk.top()]; // 1
                    stk.pop();
                    int left_bound = stk.empty() ? -1 : stk.top(); // -1
                    int width = j - left_bound - 1; // 1 - (-1) - 1 = 1
                    max_area = max(max_area, current_height * width);
                }
                stk.push(j); // stk = [1]
            }
        }

        return max_area;
    }
};