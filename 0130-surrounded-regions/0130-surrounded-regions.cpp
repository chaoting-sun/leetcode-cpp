// board (m, n) range? 1 <= m,n <= 200

// dfs problem
// 1. iterate all of the borders. if a cell is 'O', then run a DFS and mark all 'O' to '*'
// 2. iterate all cells in grid, if a cell is 'O', mark it as 'X' as it is surrounded. if a cell is '*' mark it as 'O' as it is unsurrounded. 

#include <vector>

using namespace std;

class Solution {
private:
    const int DIRECTIONS[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    void bfsBoundary(vector<vector<char>>& board, int start_row, int start_col) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        q.push({ start_row, start_col });
        board[start_row][start_col] = '*';

        while (!q.empty()) {
            auto [current_row, current_col] = q.front();
            board[current_row][current_col] = '*';
            q.pop();
            for (const auto& dir: DIRECTIONS) {
                int next_row = current_row + dir[0];
                int next_col = current_col + dir[1];
                if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n && board[next_row][next_col] == 'O') {
                    q.push({ next_row, next_col });
                    board[next_row][next_col] = '*';
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') bfsBoundary(board, i, 0);
            if (board[i][n - 1] == 'O') bfsBoundary(board, i, n - 1);
        }

        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O') bfsBoundary(board, 0, j);
            if (board[m - 1][j] == 'O') bfsBoundary(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }
};

// Submit Error

// error: use of undeclared identifier 'm'
// if (i < 0 || i >= m || j < 0 || j >= n) return;
// if (board[j][j] != 'O') return;
// int m = board.size();
// int n = board[0].size(); 
// to
// int m = board.size();
// int n = board[0].size(); 
// if (i < 0 || i >= m || j < 0 || j >= n) return;
// if (board[j][j] != 'O') return;

// error: typo
// if (board[j][j] != 'O') return;
// to
// if (board[i][j] != 'O') return;

// Dry Run

// test case: board = [[O]]
// board will not be changed

// test case: board =
// [["X","X","X","X"],
//  ["X","O","O","X"],
//  ["X","X","O","X"],
//  ["X","O","X","X"]]
// trace
// m = 4, n = 4
// i=0, j=0, (true && false)==false
// i=3, j=1, (3==4-1 && true)==true
// > captureUnsurroundedRegion(board, 3, 1)
//   - cond: (3 < 0 || 3 >= 4 || 1 < 0 || 1 >= 4) -> false
//   - cond: O != O -> false
//   - board[3][1] = '*'
//   > captureUnsurroundedRegion(board, 2, 1)
//      - cond: X != O -> true -> return
//   > captureUnsurroundedRegion(board, 4, 1)
//      - cond: 4 >= 4 -> true -> return
//   > captureUnsurroundedRegion(board, 3, 0)
//      - cond: X != O -> true -> return
//   > captureUnsurroundedRegion(board, 3, 2)
//      - cond: X != O -> true -> return