class Solution {
public:
	long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
		// preprocess the earnings
		unordered_map<int, vector<pair<int,int>>> profits;
		for (const auto& ride: rides) {
	int start = ride[0], end = ride[1], tip = ride[2];
	int profit = end - start + tip;
	profits[end].push_back({ start, profit });
}

vector<int> dp(n + 1, 0);
// end > start >= 1, so we start at i = 2
for (int i = 2; i <= n; i++) {
	// if there is no ride that ends at i, then the profit is not changed
	if (!profits.count(i)) {
	dp[i] = dp[i - 1];
} else {
	for (const auto [start, profit]: profits[i]) {
		dp[i] = max(dp[i], dp[start] + profit);
}
}
}
		return dp[n];
}
};
