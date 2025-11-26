class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> downwardMaxLength(n, 1), upwardMaxLength(n, 1);
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                if (nums[j] > nums[i]) {
                    downwardMaxLength[i] = max(downwardMaxLength[i], upwardMaxLength[j] + 1);
                }
            }
            for (int j = 0; j <= i - 1; j++) {
                if (nums[j] < nums[i]) {
                    upwardMaxLength[i] = max(upwardMaxLength[i], downwardMaxLength[j] + 1);
                }
            }
            maxLength = max(maxLength, max(downwardMaxLength[i], upwardMaxLength[i]));
        }
        return maxLength;
    }
};

// [1] -> 1
// [1, 2] -> 2
// [1, 2, 1]
// downward = [1, 1, 3]
// upward   = [1, 2, 1]

// 每個元素可能都有離他最近比他大或小的元素

// [3, 5, 3, 2]
// down
// [1  ]
// up
// [1. ]

// downward(n)
// upward(n)

// downwardMaxLength[0] = 1

// downwardMaxLength[i] = 
// nums[j] > nums[i] -> upwardMaxLength[j], j = 0 ~ i - 1

// upwardMaxLength[i] = 
// nums[j] < nums[i] -> downwardMaxLength[j], j = 0 ~ i - 1