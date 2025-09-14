// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        priority_queue<int> pq;
        unordered_set<int> visited;
        
        for (int val: nums) {
            if (!visited.count(val)) {
                pq.push(val);    
            }
            visited.insert(val);
        }
        
        vector<int> ans;
        while (!pq.empty() && k > 0) {
            ans.push_back(pq.top());
            pq.pop();
            k--;
        }
        return ans;
    }
};