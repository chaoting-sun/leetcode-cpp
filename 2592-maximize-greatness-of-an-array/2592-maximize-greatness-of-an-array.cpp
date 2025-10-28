class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n: nums) pq.push(n);
        sort(nums.begin(), nums.end());
        for (int n: nums) {
            while (!pq.empty() && pq.top() <= n) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};
