class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq; // max heap (dist^2, index)
        vector<vector<int>> ans;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            int distSquared = x * x + y * y;
            pq.push({ distSquared, i });
            if (pq.size() > k) pq.pop();
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};