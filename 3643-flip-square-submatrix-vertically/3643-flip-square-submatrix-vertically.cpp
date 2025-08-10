class Solution {
public:
    // Time: O(k^2)
    // Space: O(1)

    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();        

        for (int i = y; i < y + k; i++) {
            int top = x, bottom = x + k - 1;
            while (top < bottom) {
                int tmp = grid[top][i];
                grid[top][i] = grid[bottom][i];
                grid[bottom][i] = tmp;
                top++;
                bottom--;
            }
        }

        return grid;
    }
};