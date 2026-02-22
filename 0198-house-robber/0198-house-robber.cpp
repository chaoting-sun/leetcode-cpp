class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp_rob(n + 1, 0); // nums[i - 1] -> dp1[i]
        vector<int> dp_not_rob(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp_rob[i] = dp_not_rob[i - 1] + nums[i - 1];
            dp_not_rob[i] = max(dp_rob[i - 1], dp_not_rob[i - 1]);
        }
        
        return max(dp_rob[n], dp_not_rob[n]);
    }
};

// i:
// i - 1 is stolen -> i: x
// i - 1 is not stolen -> i: x, o

// dp1: dp[i] max money from 0 to i if i is stolen
// dp2: dp[i] max money from 0 to i if i is not stolen
// answer max(dp1[n], dp2[n])