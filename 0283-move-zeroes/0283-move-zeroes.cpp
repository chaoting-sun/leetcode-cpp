class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return;
        
        int left = 0;
        int right = 0;
        while (right < length) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
                right++;
            } else {
                right++;
            }
        }
    }
};

// CE: return 0 -> return