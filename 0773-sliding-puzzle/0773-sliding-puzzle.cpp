class Solution {
public:
    string getHash(vector<vector<int>>& board) {
        int m = 2, n = 3;
        string hash = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hash += to_string(board[i][j]);
            }
        }
        return hash;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2, n = 3;
        vector<int> rows { -1, 1, 0, 0 };
        vector<int> cols { 0, 0, -1, 1 };
        
        string start = getHash(board);
        string target = "123450";

        int startIdx = 0;
        for (int i = 0; i < m * n; i++) {
            if (start[i] == '0') {
                startIdx = i;
                break;
            }
        }

        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({ start, startIdx });
        visited.insert(start);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [curr, idx] = q.front();
                q.pop();
                int r = idx / n;
                int c = idx % n;
                
                if (curr == target) return steps;

                for (int i = 0; i < 4; i++) {
                    string next = curr;
                    int drow = rows[i];
                    int dcol = cols[i];
                    
                    int nextIdx = 0;
                    if (drow != 0) {
                        int nr = r + drow;
                        if (nr < 0 || nr >= m) continue;
                        nextIdx = nr * n + c;
                    } else {
                        int nc = c + dcol;
                        if (nc < 0 || nc >= n) continue;
                        nextIdx = r * n + nc;
                    }

                    swap(next[idx], next[nextIdx]);

                    if (visited.count(next)) continue;
                    visited.insert(next);
                    q.push({ next, nextIdx });
                }
            }
            steps++;
        }
        return -1;
    }
};