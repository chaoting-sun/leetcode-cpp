class Solution {
public:
    // Approach1: sort and check in sequential

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());
        
        int current = nums[0];
        int count = 1, max_count = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == current) continue;

            if (nums[i] == current + 1) {
                count++;
            } else {
                max_count = max(max_count, count);
                count = 1;
            }
            current = nums[i];
        }
        
        return max(max_count, count);
    }
};

// 0 0 1

// [9,1,4,7,3,-1,0,5,8,-1,6]
// [-1,-1,0,1,3,4,5,6,7,8,9]

// current = 0, count = 1, max_count = 1
// 0 -> continue
// 1 -> count = 2
// 1 -> count = 2, current = 1
// 2 -> count = 