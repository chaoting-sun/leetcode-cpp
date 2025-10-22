class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> ans;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }

    // Approach: Hash Table
    // Time: O(n + m)
    // Space: O(min(n, m))
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     if (nums1.size() > nums2.size()) {
    //         return intersect(nums2, nums1);
    //     }
        
    //     unordered_map<int,int> candidates;
    //     for (int n: nums1) candidates[n]++;
    //     vector<int> ans;
    //     for (int n: nums2) {
    //         if (candidates.count(n)) {
    //             ans.push_back(n);
    //             candidates[n]--;
    //             if (candidates[n] == 0) candidates.erase(n);
    //         }
    //     }
    //     return ans;
    // }
};