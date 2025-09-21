class Solution {
public:
    // Approach: Hash map
    // nums1[i] + nums2[j] == -(nums3[k] + nums4[l])
    // We record all combination of nums1[i] + nums2[j] in hash map, and then try all combination of
    // nums3[k] + nums4[l] to find if -(nums3[k] + nums4[l]) is in the hash map.

    // Time: O(n^2)
    // Space: O(n^2)

    // int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    //     unordered_map<int,int> twoSum;
    //     for (int v1: nums1) {
    //         for (int v2: nums2) {
    //             twoSum[v1 + v2]++;
    //         }
    //     }

    //     int ans = 0;
    //     for (int v3: nums3) {
    //         for (int v4: nums4) {
    //             int currentTwoSum = v3 + v4;
    //             if (twoSum.count(-currentTwoSum)) {
    //                 ans += twoSum[-currentTwoSum];
    //             }
    //         }
    //     }

    //     return ans;
    // }

    // Generalized Method

    unordered_map<int,int> countSum(int start, int end, vector<vector<int>>& lists) {
        unordered_map<int,int> count({ { 0, 1 } });
        for (int i = start; i < end; i++) {
            unordered_map<int,int> temp;
            for (auto c: count) {
                for (int val: lists[i]) {
                    temp[c.first + val] += c.second;
                }
            }
            count = temp;
        }
        return count;
    };

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<vector<int>> lists = { nums1, nums2, nums3, nums4 };

        int k = lists.size();
        unordered_map<int,int> count1 = countSum(0, k/2, lists);
        unordered_map<int,int> count2 = countSum(k/2, k, lists);

        int ans = 0;
        for (auto [c1, v1]: count1) {
            for (auto [c2, v2]: count2) {
                if (c1 + c2 == 0) ans += v1 * v2;
            }
        }
        return ans;
    }
};