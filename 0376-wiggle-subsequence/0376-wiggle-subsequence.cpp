class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            int prev_up = up, prev_down = down;
            if (nums[i - 1] < nums[i]) {
                up = prev_down + 1;
                down = prev_down;
            } else if (nums[i - 1] > nums[i]) {
                down = prev_up + 1;
                up = prev_up;
            } else {
                up = prev_up;
                down = prev_down;
            }
        }
        return max(up, down);
    }
};


// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> down(n, 1), up(n, 1);
//         for (int i = 1; i < n; i++) {
//             if (nums[i - 1] < nums[i]) {
//                 up[i] = down[i - 1] + 1;
//                 down[i] = down[i - 1];
//             } else if (nums[i - 1] > nums[i]) {
//                 down[i] = up[i - 1] + 1;
//                 up[i] = up[i - 1];
//             } else {
//                 up[i] = up[i - 1];
//                 down[i] = down[i - 1];
//             }
//         }
//         return max(up[n - 1], down[n - 1]);
//     }
// };


// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> downwardMaxLength(n, 1), upwardMaxLength(n, 1);
//         int maxLength = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j <= i - 1; j++) {
//                 if (nums[j] > nums[i]) {
//                     downwardMaxLength[i] = max(downwardMaxLength[i], upwardMaxLength[j] + 1);
//                 }
//             }
//             for (int j = 0; j <= i - 1; j++) {
//                 if (nums[j] < nums[i]) {
//                     upwardMaxLength[i] = max(upwardMaxLength[i], downwardMaxLength[j] + 1);
//                 }
//             }
//             maxLength = max(maxLength, max(downwardMaxLength[i], upwardMaxLength[i]));
//         }
//         return maxLength;
//     }
// };

// [2 4 3 2]

// downwardMaxLength[]

// nums[i -1] < nums[i] -> {
//     upwardMaxLength[i] 繼承 upwardMaxLength[i - 1]
    
// }
// nums[i - 1] > nums[i] -> {
//     downwardMaxLength[i] 繼承 downwardMaxLength[i - 1]
// }