class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sz = nums.size();
        vector<int> slot(sz);

        for (int i = 0; i < sz; i++) {
            slot[nums[i]]++;
        }

        for (int i = 1; i < sz; i++) {
            if (slot[i] > 1) return i;
        }
        return -1;
    }
};