class Solution {
public:
    // Approach: Max Heap
    // Time: O(n*logn)
    // Space: O(n)

    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // distance^2, index

    //     for (int i = 0; i < points.size(); i++) {
    //         int x = points[i][0];
    //         int y = points[i][1];
    //         pq.push({ x*x + y*y, i });
    //     }

    //     vector<vector<int>> ans;

    //     while (k--) {
    //         int index = pq.top().second;
    //         pq.pop();
    //         ans.push_back(points[index]);
    //     }

    //     return ans;
    // }

    // Approach: Sort
    // Time: O(n*logn)
    // Space: O(n)

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> distances;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            distances.push_back({ x*x + y*y, i });
        }

        sort(distances.begin(), distances.end());

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++) {
            int index = distances[i].second;
            ans.push_back(points[index]);
        }

        return ans;
    }
};