class Solution {
public:
    // Approach1: put the queen row by row and check if each position is valid
    // Time: O(n*n!). in 1st row, we can choose from n position. in 2nd row, we at most can
    // choose from n - 2 position, this pattern continues, resulting in an approximate time
    // complexity of n!. for each position, we need O(n) to check the validity.
    // Space: O(n^2)

    // vector<vector<string>> ans;

    // void backtrack(int n, int row, vector<vector<bool>>& is_placed, vector<string>& placement) {
    //     if (row == n) {
    //         ans.push_back(placement);
    //         return;
    //     }

    //     int r, c;
    //     for (int col = 0; col < n; col++) {
    //         int valid = true;
            
    //         r = 0;
    //         while (r < row) {
    //             if (is_placed[r][col]) {
    //                 valid = false;
    //                 break;
    //             }
    //             r++;
    //         }
    //         if (!valid) continue;
            
    //         r = row - 1;
    //         c = col - 1;
    //         while (r >= 0 && c >= 0) {
    //             if (is_placed[r][c]) {
    //                 valid = false;
    //                 break;
    //             }
    //             r--;
    //             c--;
    //         }
    //         if (!valid) continue;

    //         r = row - 1;
    //         c = col + 1;
    //         while (r >= 0 && c < n) {
    //             if (is_placed[r][c]) {
    //                 valid = false;
    //                 break;
    //             }
    //             r--;
    //             c++;
    //         }
    //         if (!valid) continue;

    //         is_placed[row][col] = true;
    //         placement.push_back(string(n, '.').replace(col, 1, "Q"));

    //         backtrack(n, row + 1, is_placed, placement);

    //         is_placed[row][col] = false;
    //         placement.pop_back();
    //     }
    // }

    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<bool>> is_placed(n, vector<bool>(n, false));
    //     vector<string> placement;

    //     backtrack(n, 0, is_placed, placement);
    //     return ans;
    // }

    // Approach2: 

    vector<vector<string>> ans;
    set<int> colSet, posSet, negSet;

    void backtrack(int n, int row, vector<string>& placement) {
        if (row == n) {
            ans.push_back(placement);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (colSet.find(col) != colSet.end()) {
                continue;
            }
            if (posSet.find(col - row) != posSet.end()) {
                continue;
            }
            if (negSet.find(col + row) != negSet.end()) {
                continue;
            }

            colSet.insert(col);
            posSet.insert(col - row);
            negSet.insert(col + row);
            placement.push_back(string(n, '.').replace(col, 1, "Q"));

            backtrack(n, row + 1, placement);

            colSet.erase(col);
            posSet.erase(col - row);
            negSet.erase(col + row);
            placement.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> placement;
        backtrack(n, 0, placement);
        return ans;
    }    
};
