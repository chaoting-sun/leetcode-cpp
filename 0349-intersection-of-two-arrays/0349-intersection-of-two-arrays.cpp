class Solution {
public:
    // Approach: Merge
    // Time: O(nlogn + mlogm)
    // Space: O(1)
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     sort(nums1.begin(), nums1.end());
    //     sort(nums2.begin(), nums2.end());
    //     int i = 0, j = 0;
    //     vector<int> ans;
    //     while (i < nums1.size() && j < nums2.size()) {
    //         if (nums1[i] == nums2[j]) {
    //             if (ans.empty() || ans.back() != nums1[i]) {
    //                 ans.push_back(nums1[i]);
    //             }
    //             i++;
    //             j++;
    //         } else if (nums1[i] < nums2[j]) {
    //             i++;
    //         } else {
    //             j++;
    //         }
    //     }
    //     return ans;
    // }

    // Approach: Hash Table
    // Time: O(n)
    // Space: O(n)
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