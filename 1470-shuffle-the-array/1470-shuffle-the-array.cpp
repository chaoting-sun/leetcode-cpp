class Solution {
public:
    // Time: O(n)
    // Space: O(n)

    // vector<int> shuffle(vector<int>& nums, int n) {
    //     vector<int> ans(2 * n);
    //     for (int i = 0; i < n; i++) ans[i * 2] = nums[i];
    //     for (int i = n; i < 2*n; i++) ans[2 * (i - n) + 1] = nums[i];
    //     return ans;
    // }

    // Time: O(n)
    // Space: O(1)

    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        int xIndex = 0, yIndex = n;
        int i = 0;

        for (int j = 0; j < n; j++) {
            ans[i] = nums[xIndex];
            ans[i + 1] = nums[yIndex];
            i += 2;
            xIndex++;
            yIndex++;
        }
        return ans;
    }
};
