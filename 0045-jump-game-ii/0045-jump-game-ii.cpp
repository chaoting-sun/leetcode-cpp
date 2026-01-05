class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> max_reach(n);
        for (int i = 0; i < n; i++) {
            max_reach[i] = min(n - 1, i + nums[i]);
        }

        int jumps = 0;
        int current_reach = 0;
        int next_reach = 0;
        
        for (int i = 0; i < n - 1; i++) {
            next_reach = max(next_reach, max_reach[i]);
            if (i == current_reach) {
                if (next_reach <= i) return -1;
                current_reach = next_reach;
                jumps++;
            }
        }

        return current_reach == n - 1 ? jumps : -1;
    }
};

// nums = [2,3,1,1,4]
//         0 1 2 3 4
// max_reach = [2,4,3,4,5]