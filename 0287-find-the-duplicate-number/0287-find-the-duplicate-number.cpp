class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        fast = nums[nums[fast]];
        slow = nums[slow];
        while (fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int prev = 0;
        while (prev != slow) {
            prev = nums[prev];
            slow = nums[slow];
        }
        return prev;
    }
};

