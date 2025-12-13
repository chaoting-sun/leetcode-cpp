// board (m, n) range? 1 <= m,n <= 200

// dfs problem
// iterate board, do dfs on all unvisited cells.
// for each dfs, storing all visited positions in a vector. if when no edges have not visited, update all visited positions 

class Solution {
private:
    bool captureSurroundedRegion(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, vector<pair<int,int>>& current_visited) {
        int m = board.size();
        int n = board[0].size(); 
        
        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return false;
        if (visited[x][y]) return true;

        visited[x][y] = true;
        current_visited.push_back({ x, y });

        int is_surrounded = true;
        if (x > 0 && board[x - 1][y] == 'O') is_surrounded &= captureSurroundedRegion(board, visited, x - 1, y, current_visited);
        if (x < m - 1 && board[x + 1][y] == 'O') is_surrounded &= captureSurroundedRegion(board, visited, x + 1, y, current_visited);
        if (y > 0 && board[x][y - 1] == 'O') is_surrounded &= captureSurroundedRegion(board, visited, x, y - 1, current_visited);
        if (y < n - 1 && board[x][y + 1] == 'O') is_surrounded &= captureSurroundedRegion(board, visited, x, y + 1, current_visited);
        return is_surrounded;
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int x = 1; x < m - 1; x++) {
            for (int y = 1; y < n - 1; y++) {
                if (visited[x][y] || board[x][y] != 'O') continue;
                vector<pair<int,int>> current_visited;
                bool is_surrounded_region = captureSurroundedRegion(board, visited, x, y, current_visited);
                if (is_surrounded_region) {
                    for (const auto& [visited_x, visited_y]: current_visited) {
                        board[visited_x][visited_y] = 'X';
                    }
                }
            }
        }
    }
};

// test case: board = [[O]]
// board will not be changed
