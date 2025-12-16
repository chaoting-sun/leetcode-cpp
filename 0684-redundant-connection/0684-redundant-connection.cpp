class Solution {
private:
	struct DSU {
	vector<int> size;
	vector<int> parent;
	
	DSU(int n) {
	size.assign(n, 1);
	parent.resize(n);
	iota(parent.begin(), parent.end(), 0);
}

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
	int root_u = find(u);
	int root_v = find(v);
	if (root_u != root_v) {
		if (size[root_u] > size[root_v]) {
	swap(root_u, root_v);
}
parent[root_u] = root_v;
size[root_v] += size[root_u];
}
}
};
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	int n = edges.size();

	DSU dsu(n + 1);
	vector<int> last_redundant_edge { 0, 0 };
	for (const auto& edge: edges) {
	int u = edge[0], v = edge[1];
	if (dsu.find(u) != dsu.find(v)) {
	dsu.unite(u, v);
} else {
	last_redundant_edge = edge;
}
}
	return last_redundant_edge;
}
};
