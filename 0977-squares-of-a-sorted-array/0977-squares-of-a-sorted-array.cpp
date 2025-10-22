class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int zeroOrPosIdx = n;
        int negIdx = -1;
        while (zeroOrPosIdx - 1 >= 0 && nums[zeroOrPosIdx - 1] >= 0)
            zeroOrPosIdx--;
        while (negIdx + 1 < n && nums[negIdx + 1] < 0)
            negIdx++;

        vector<int> ans;
        while (0 <= negIdx && zeroOrPosIdx < n) {
            if (nums[zeroOrPosIdx] <= -nums[negIdx]) {
                ans.push_back(nums[zeroOrPosIdx] * nums[zeroOrPosIdx]);
                zeroOrPosIdx++;
            } else {
                ans.push_back(nums[negIdx] * nums[negIdx]);
                negIdx--;
            }
        }
        while (0 <= negIdx) {
            ans.push_back(nums[negIdx] * nums[negIdx]);
            negIdx--;
        }
        while (zeroOrPosIdx < n) {
            ans.push_back(nums[zeroOrPosIdx] * nums[zeroOrPosIdx]);
            zeroOrPosIdx++;
        }
        return ans;
    }
};