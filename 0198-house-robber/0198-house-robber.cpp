class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> max_money(n + 1, 0);
        max_money[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            max_money[i] = max(max_money[i - 2] + nums[i - 1], max_money[i - 1]);
        }
        
        return max_money[n];
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         int max_prev_rob = 0, max_prev_not_rob = 0;

//         for (int i = 1; i <= n; i++) {
//             int tmp_max_prev_rob = max_prev_rob;
//             max_prev_rob = max_prev_not_rob + nums[i - 1];
//             max_prev_not_rob = max(tmp_max_prev_rob, max_prev_not_rob);
//         }
        
//         return max(max_prev_rob, max_prev_not_rob);
//     }
// };