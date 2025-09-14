int M = 1e9 + 7;

class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        int e1 = 0;
        int e2 = 0;
        int o1 = 0;
        int o2 = 0;

        for (int i = 0; i < n; i++) {
            // odd
            if (nums[i] % 2 == 1) {
                // choose
                o2 += o1;
                o1 += (e1 + e2 + 1) % M;
                o1 %= M;
                o2 %= M;
            }
            // even
            else {
                e2 += e1;
                e1 += (o1 + o2 + 1) % M;
                e1 %= M;
                e2 %= M;
            }
        }

        return ((o1 + o2) % M + (e1 + e2) % M) % M;
    }
};

