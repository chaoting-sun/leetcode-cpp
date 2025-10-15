class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<int,double>> workers(n);
        for (int i = 0; i < n; i++) {
            workers[i] = { quality[i], 1.0 * wage[i] / quality[i] };
        }
        sort(workers.begin(), workers.end(), [](pair<int,double>& a, pair<int,double>& b) {
            return a.second < b.second;
        });
        priority_queue<int> pq; // max heap
        double totalQualities = 0;
        double minCost = DBL_MAX;

        for (auto& [q, wPerQ]: workers) {
            totalQualities += q;
            pq.push(q);
            if (pq.size() > k) {
                totalQualities -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                minCost = min(minCost, totalQualities * wPerQ);
            }
        }
        return minCost;
    }
};

// [4,8,2,2,7]

// [3,    1,  10,  10, 1]
// [1.33, 8, 0.2, 0.2, 7]

// [1, 1,    3,  10, 10]
// [8, 7, 1.33, 0.2, 0.2]

// q=[10,20,5]
// w=[70,50,30]
// p=[7,2.5,6]

// q=[10,5,20]
// p=[7,6,2.5]

//   70 35

