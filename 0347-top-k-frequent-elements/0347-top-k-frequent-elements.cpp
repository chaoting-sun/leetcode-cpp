class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n: nums) {
            if (count.find(n) == count.end()) {
                count.insert({ n, 1 });
            } else {
                count[n]++;
            }
        }

        priority_queue<pair<int, int>> pq;
        for (auto c: count) {
            pq.push(make_pair(c.second, c.first));
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};