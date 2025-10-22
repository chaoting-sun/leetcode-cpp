class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> occurrence;
        unordered_set<int> seen;
        for (int n: nums1) occurrence.insert(n);
        for (int n: nums2) {
            if (occurrence.count(n)) seen.insert(n);
        }
        vector<int> ans(seen.begin(), seen.end());
        return ans;
    }
};