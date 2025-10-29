class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int n: nums) {
            if (n > nums[i]) {
                ans++;
                i++;
            }
        }
        return ans;
    }
};
