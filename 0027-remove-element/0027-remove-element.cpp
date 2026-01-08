class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int write = 0;
        for (int read = 0; read < n; read++) {
            if (nums[read] != val) {
                if (write != read) nums[write] = nums[read];
                write++;
            }
        }
        return write;
    }
};