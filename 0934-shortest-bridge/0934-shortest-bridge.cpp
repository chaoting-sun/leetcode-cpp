class Solution {
private:
	const vector<vector<int>> DIRECTIONS = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
public:
	int shortestBridge(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	
	int start_x = 0, start_y = 0;
	bool found = false;
	for (int i = 0; i < m; i++) {
		if (found) break;
	for (int j = 0; j < n; j++) {
	if (grid[i][j] == 1) {
	start_x = i;
	start_y = j;
	found = true;
	break;
}
}
}

queue<pair<int,int>> explore_q, source_q;
explore_q.push({ start_x, start_y });
source_q.push({ start_x, start_y });
grid[start_x][start_y] = -1;

while (!explore_q.empty()) {
	auto [x, y] = explore_q.front();
	explore_q.pop();

	for (const auto& dir: DIRECTIONS) {
		int neighbor_x = x + dir[0];
int neighbor_y = y + dir[1];
if (neighbor_x < 0 || neighbor_x >= m || neighbor_y < 0 || neighbor_y >= n) {
continue;
}
if (grid[neighbor_x][neighbor_y] != 1) continue;
explore_q.push({ neighbor_x, neighbor_y });
source_q.push({ neighbor_x, neighbor_y });
grid[neighbor_x][neighbor_y] = -1;
}
}

		int distance = 0;
		while (!source_q.empty()) {
int size = source_q.size();
while (size--) {
	auto [x, y] = source_q.front();
	source_q.pop();
	if (grid[x][y] == 1) return distance;

	for (const auto& dir: DIRECTIONS) {
		int neighbor_x = x + dir[0];
int neighbor_y = y + dir[1];
if (neighbor_x < 0 || neighbor_x >= m || neighbor_y < 0 || neighbor_y >= n) {
	continue;
}
if (grid[neighbor_x][neighbor_y] == 1) return distance;
if (grid[neighbor_x][neighbor_y] == -1) continue;
source_q.push({ neighbor_x, neighbor_y });
grid[neighbor_x][neighbor_y] = -1;
	}
	
}

	distance++;
}
return distance;
}
};
