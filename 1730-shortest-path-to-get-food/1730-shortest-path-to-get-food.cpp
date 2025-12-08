class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        // 1. find the '*'
        // 2. BFS from '*': search 4 directions in each cell
        //  - O -> keep the cell; set it to X
        //  - X -> neglect the path
        //  - # -> return the distance

        int m = grid.size();
        if (m == 0) return -1;
        int n = grid[0].size();
        if (n == 0) return -1;

        vector<pair<int,int>> directions {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 },
        };

        int start_x = 0, start_y = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        queue<pair<int,int>> cells;
        cells.push({ start_x, start_y });
        int distance = 0;

        while (!cells.empty()) {
            distance++;

            int size = cells.size();
            while (size--) {
                auto [x, y] = cells.front();
                cells.pop();

                for (const auto [dx, dy]: directions) {
                    int new_x = x + dx;
                    int new_y = y + dy;
                    if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;
                    if (grid[new_x][new_y] == 'O') {
                        cells.push({ new_x, new_y });
                        grid[new_x][new_y] = 'X';
                    } else if (grid[new_x][new_y] == '#') {
                        return distance;
                    }
                }
            }            
        }

        return -1;
    }
};