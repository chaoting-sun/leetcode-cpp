class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> candidates;
        for (int n: nums1) candidates[n]++;
        vector<int> ans;
        for (int n: nums2) {
            if (candidates.count(n)) {
                ans.push_back(n);
                candidates[n]--;
                if (candidates[n] == 0) candidates.erase(n);
            }
        }
        return ans;
    }
};