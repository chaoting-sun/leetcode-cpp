class Solution {
public:
    // Approach: binary search on the first column to get the row and then binary search on the row to find the value
    // Time: O(log(n*m))
    // Space: O(1)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // find the first value that is larger than target
        int top = 0, bottom = n;
        while (top < bottom) {
            int mid = (top + bottom) / 2;
            if (matrix[mid][0] < target) {
                top = mid + 1;
            } else if (matrix[mid][0] > target) {
                bottom = mid;
            } else {
                return true;
            }
        }

        int row = top == 0 ? 0 : top - 1;

        int left = 0, right = m;
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] < target) {
                left = mid + 1;
            } else if (matrix[row][mid] > target) {
                right = mid;
            } else {
                return true;
            }
        }

        return false;
    }
};