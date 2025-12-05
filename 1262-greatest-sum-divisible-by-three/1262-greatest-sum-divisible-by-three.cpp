// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp { 0, 0, 0 };
        
//         for (int i = 0; i < n; i++) {
//             vector<int> next_dp = dp;

//             for (int j = 0; j < 3; j++) {
//                 int currSum = dp[j] + nums[i];
//                 int remainder = currSum % 3;
//                 next_dp[remainder] = max(currSum, next_dp[remainder]);
//             }

//             dp = next_dp;
//         }
//         return dp[0];
//     }
// };

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int max_val = 10001;
        int min1_rem1 = max_val, min1_rem2 = max_val;
        int min2_rem1 = max_val, min2_rem2 = max_val;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] % 3 == 1) {
                if (nums[i] < min1_rem1) {
                    int tmp = min1_rem1;
                    min1_rem1 = nums[i];
                    min2_rem1 = tmp;
                } else if (nums[i] < min2_rem1) {
                    min2_rem1 = nums[i];
                }
            } else if (nums[i] % 3 == 2) {
                if (nums[i] < min1_rem2) {
                    int tmp = min1_rem2;
                    min1_rem2 = nums[i];
                    min2_rem2 = tmp;
                } else if (nums[i] < min2_rem2) {
                    min2_rem2 = nums[i];
                }
            }
        }

        int totalSum = 0;
        for (int v: nums) totalSum += v;
        
        if (totalSum % 3 == 0) {
            return totalSum;
        } else if (totalSum % 3 == 1) {
            return totalSum - min(min1_rem1, min1_rem2 + min2_rem2);
        } else {
            return totalSum - min(min1_rem2, min1_rem1 + min2_rem1);
        }
    }
};

// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         int n = nums.size();
//         int maxSum = 0;
//         for (int val: nums) maxSum += val;
//         if (maxSum % 3 == 0) return maxSum;

//         sort(nums.begin(), nums.end());
        
//         int ans = 0;
//         int check = 0;
//         int leftSum = maxSum;

//         // 1 -> 刪1個餘1的數 ^ 或2個餘2的數

//         if (maxSum % 3 == 1) {
//             for (int i = 0; i < n; i++) {
//                 if (nums[i] % 3 == 1) {
//                     leftSum -= nums[i];
//                     ans = leftSum;
//                     break;
//                 }
//             }

//             leftSum = maxSum;
//             for (int i = 0; i < n; i++) {
//                 if (nums[i] % 3 == 2) {
//                     leftSum -= nums[i];
//                     check++;
//                     if (check == 2) {
//                         ans = max(ans, leftSum);
//                         break;
//                     }
//                 }
//             }
//         } else {
//             // 刪1個餘2的數 或 刪2個餘1的數

//             leftSum = maxSum;
//             for (int i = 0; i < n; i++) {
//                 if (nums[i] % 3 == 2) {
//                     leftSum -= nums[i];
//                     ans = leftSum;
//                     break;
//                 }
//             }

//             leftSum = maxSum; 
//             check = 0;
//             for (int i = 0; i < n; i++) {
//                 if (nums[i] % 3 == 1) {
//                     leftSum -= nums[i];
//                     check++;
//                     if (check == 2) {
//                         ans = max(ans, leftSum);
//                         break;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

// // [1,3,5,6,8] -> 23 % 3 == 2

