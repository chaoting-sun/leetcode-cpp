class Solution {
public:
    // Intuition: One method is starting from the cell (i,j) with 0<i<m-1, 0<j<n-1, board[i][j]='O' and dfs
    // but it is hard to implement as we have to track the paths before we check this is the surrounded region.
    // we can do it in an opposite way. we start from the border with board[i][j] = 'O' and dfs those connected
    // 'O' and mark them '#'. any cell that is marked as '#' is not surrounded by 'X'.
    
    // Approach: DFS
    // Time: O(m*n)
    // Space: O(m*n). the depth of the function call stack, in worst case, is the number of cells

    // void dfs(vector<vector<char>>& board, int i, int j) {
    //     int m = board.size();
    //     int n = board[0].size();

    //     // termination condition
    //     if (i < 0 || i >= m || j < 0 || j >= n) {
    //         return;
    //     }
    //     if (board[i][j] == 'X' || board[i][j] == '#') return;

    //     // visited
    //     board[i][j] = '#';

    //     dfs(board, i - 1, j);
    //     dfs(board, i + 1, j);
    //     dfs(board, i, j - 1);
    //     dfs(board, i, j + 1);
    // }

    // void solve(vector<vector<char>>& board) {
    //     int m = board.size();
    //     int n = board[0].size();

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j]) {
    //                 dfs(board, i, j);
    //             }
    //         }
    //     }

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (board[i][j] == '#') {
    //                 board[i][j] = 'O';
    //             } else if (board[i][j] == 'O') {
    //                 board[i][j] = 'X';
    //             }
    //         }
    //     }
    // }

    // Approach: BFS
    // Time: O(m*n)
    // Space: O(m+n)

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> cells;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    cells.push({ i, j });
                    board[i][j] = '#';
                }
            }
        }

        vector<int> dx { 0, 0, 1, -1 };
        vector<int> dy { 1, -1, 0, 0 };

        while (!cells.empty()) {
            int size = cells.size();

            for (int i = 0; i < size; i++) {
                int x = cells.front().first;
                int y = cells.front().second;
                cells.pop();

                for (int j = 0; j < 4; j++) {
                    int newx = x + dx[j];
                    int newy = y + dy[j];
                    if (newx >= 0 && newx < m && newy >= 0 && newy < n && board[newx][newy] == 'O') {
                        cells.push({ newx, newy });
                        board[newx][newy] = '#';
                    }
                    
                }
                
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};