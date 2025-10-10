class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(solve(nums1, nums2), solve(nums2, nums1));
    }

    int solve(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> gain(n);
        for (int i = 0; i < n; i++) gain[i] = nums1[i] - nums2[i];
        
        int currentMaxGain = 0;
        int globalMaxGain = INT_MIN;
        for (int i = 0; i < n; i++) {
            currentMaxGain = max(gain[i], currentMaxGain + gain[i]);
            globalMaxGain = max(globalMaxGain, currentMaxGain);
        }

        int totalSum = 0;
        for (int n: nums2) totalSum += n;

        return totalSum + globalMaxGain;
    }
};