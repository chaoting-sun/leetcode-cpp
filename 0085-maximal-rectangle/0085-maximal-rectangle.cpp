class Solution {
public:
    int maximalRectangle(vector<int> heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);    
        stack<int> index_stack;
        int max_area = 0;

        for (int i = 0; i < (int)heights.size(); i++) {
            while (!index_stack.empty() && heights[index_stack.top()] > heights[i]) {
                int height = heights[index_stack.top()];
                index_stack.pop();
                int width = i - index_stack.top() - 1;
                max_area = max(max_area, height * width);
            }
            index_stack.push(i);
        }
        return max_area;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n);
        int max_area = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') dp[j] = 0;
                else dp[j] += 1;
            }
            max_area = max(max_area, maximalRectangle(dp));
        }
        return max_area;
    }
};