class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int max_cnt = 0;
        int n = nums.size();
        int one_cnt = 0; // number of 1s

        while (right < n) {
            // count the number of 1s
            if (nums[right] == 1) one_cnt++;
            
            // ensure that the number of 0s is not larger then k
            while ((right - left + 1) - one_cnt > k) {
                if (nums[left] == 1) one_cnt--;
                left++;
            }
            
            max_cnt = max(max_cnt, right - left + 1);
            
            right++;
        }

        return max_cnt;
    }
};