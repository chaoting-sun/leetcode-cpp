class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        for (int val: nums) maxSum += val;
        if (maxSum % 3 == 0) return maxSum;

        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int check = 0;
        int leftSum = maxSum;

        // 1 -> 刪1個餘1的數 ^ 或2個餘2的數

        if (maxSum % 3 == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] % 3 == 1) {
                    leftSum -= nums[i];
                    ans = leftSum;
                    break;
                }
            }

            leftSum = maxSum;
            for (int i = 0; i < n; i++) {
                if (nums[i] % 3 == 2) {
                    leftSum -= nums[i];
                    check++;
                    if (check == 2) {
                        ans = max(ans, leftSum);
                        break;
                    }
                }
            }
        } else {
            // 刪1個餘2的數 或 刪2個餘1的數

            leftSum = maxSum;
            for (int i = 0; i < n; i++) {
                if (nums[i] % 3 == 2) {
                    leftSum -= nums[i];
                    ans = leftSum;
                    break;
                }
            }

            leftSum = maxSum; 
            check = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] % 3 == 1) {
                    leftSum -= nums[i];
                    check++;
                    if (check == 2) {
                        ans = max(ans, leftSum);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

// [1,3,5,6,8] -> 23 % 3 == 2

