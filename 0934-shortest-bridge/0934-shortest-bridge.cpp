class Solution {
public:
    void bfsIsland(vector<vector<int>>& grid, set<vector<int>>& visited, vector<int> start) {
        vector<int> dx = { 1, -1, 0, 0 };
        vector<int> dy = { 0, 0, 1, -1 };

        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>> cells;

        cells.push(start);
        visited.insert(start);

        while (!cells.empty()) {
            vector<int> position = cells.front();
            cells.pop();
            int x = position[0], y = position[1];
            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
                if (grid[newX][newY] == 0) continue;
                if (visited.count({ newX, newY })) continue;

                vector<int> newPosition = { newX, newY };
                cells.push(newPosition);
                visited.insert(newPosition);
            }
        }
    }


    int shortestBridge(vector<vector<int>>& grid) {
        // approach:
        // I will do BFS on one island, and use a set 'firstVisited' to store the cells
        // in the island. Then, I do another BFS on the second island, and use a set
        // 'secondVisited' to store the cells in the island. Lastly, I search for the
        // minimum distance of any pair of cells from the 'firstVisited' and 'secondVisited'
        // why:
        // Basically, this problem asks the distance of the two islands, which exactly
        // what BFS is used for.
        // complexity:
        // The time complexity is O(N^2*logn), mainly due to BFS, in which process each
        // cell is visited in logn time. The space complexity is O(N^2), mainly
        // due to the hashmap visited.

        int m = grid.size();
        int n = grid[0].size();

        set<vector<int>> firstVisited;
        bool found = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    bfsIsland(grid, firstVisited, { i, j });
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        set<vector<int>> secondVisited;
        found = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> start { i, j };
                if (firstVisited.count(start)) continue;
                if (grid[i][j] == 1) {
                    bfsIsland(grid, secondVisited, start);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        int minDistance = INT_MAX;
        for (const vector<int>& firstCell: firstVisited) {
            for (const vector<int>& secondCell: secondVisited) {
                int xDirDistance = abs(firstCell[0] - secondCell[0]);
                int yDirDistance = abs(firstCell[1] - secondCell[1]);
                minDistance = min(minDistance, xDirDistance + yDirDistance - 1);
            }
        }
        return minDistance;
    }
};
