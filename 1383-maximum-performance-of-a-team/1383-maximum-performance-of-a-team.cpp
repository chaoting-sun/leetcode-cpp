class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9 + 7;

        vector<pair<int,int>>engineers(n);
        for (int i = 0; i < n; i++) {
            engineers[i] = { speed[i], efficiency[i] };
        }
        sort(engineers.begin(), engineers.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long speedSum = 0;
        long long maxPerformance = 0;

        for (auto& engineer: engineers) {
            speedSum += engineer.first;
            pq.push(engineer.first);
            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            maxPerformance = max(maxPerformance, speedSum * engineer.second);
        }
        return maxPerformance % MOD;
    }
};

// [2,8,2]
// [2,7,1]

// [8,2,2]
// [7,2,1]