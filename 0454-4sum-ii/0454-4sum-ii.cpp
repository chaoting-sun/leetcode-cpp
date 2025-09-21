class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> twoSum;
        for (int v1: nums1) {
            for (int v2: nums2) {
                twoSum[v1 + v2]++;
            }
        }

        int ans = 0;
        for (int v3: nums3) {
            for (int v4: nums4) {
                int currentTwoSum = v3 + v4;
                if (twoSum.count(-currentTwoSum)) {
                    ans += twoSum[-currentTwoSum];
                }
            }
        }

        return ans;
    }
};