class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool isReverseOrder = true;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                isReverseOrder = false;
                break;
            }
        }
        if (isReverseOrder) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int maxValue = INT_MIN;
        vector<int> freq(101);
        for (int i = n - 1; i >= 0; i--) {
            maxValue = max(maxValue, nums[i]);
            freq[nums[i]]++;
            for (int j = nums[i] + 1; j <= maxValue; j++) {
                if (!freq[j]) continue;
                nums[i] = j;
                freq[j]--;
                int p = i + 1;
                for (int k = 0; k <= maxValue; k++) {
                    while (freq[k]--) {
                        nums[p++] = k;
                    }
                }
                return;
            }
        }
    }
};

// [1,1,5]
// [0,0,0,0,0,1]


// [1,2,3,4,5]

// [1,2,3,5,4]
// [1,2,4,3,5]
