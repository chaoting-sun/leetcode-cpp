class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        long long score = 0;
        for (int i = 0; i < n; i++) {
            pq.push({ nums[i], i });
        }
        while (!pq.empty()) {
            while (!pq.empty() && marked[pq.top().second]) {
                pq.pop();
            }
            if (pq.empty()) break;

            auto [val, idx] = pq.top();
            pq.pop();
            score += val;
            marked[idx] = true;
            if (idx > 0) marked[idx - 1] = true;
            if (idx < n - 1) marked[idx + 1] = true;
        }
        return score;
    }
};