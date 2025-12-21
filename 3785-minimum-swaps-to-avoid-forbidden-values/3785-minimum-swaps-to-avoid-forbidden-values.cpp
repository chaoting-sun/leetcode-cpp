class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        
        unordered_map<int,int> nums_count, forbidden_count;
        for (int n: nums) nums_count[n]++;
        for (int n: forbidden) forbidden_count[n]++;

        for (auto [val, freq]: nums_count) {
            if (freq + forbidden_count[val] > n) {
                return -1;
            }
        }
  
        unordered_map<int,int> bad_freq;
        int bad_count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == forbidden[i]) {
                bad_freq[nums[i]]++;
                bad_count++;
            }
        }

        if (bad_count == 0) return 0;

        int max_bad_count = 0;
        for (auto [val, freq]: bad_freq) {
            if (freq > max_bad_count) {
                max_bad_count = freq;
            }
        }

        return max((bad_count + 1) / 2, max_bad_count);
    }
};