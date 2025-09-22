class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 2) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int sumUpperBound = target - nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] >= sumUpperBound) {
                    right--;
                    continue;
                }
                count += right - left;
                left++;
            }
        }
        return count;
    }
};

// ex: [-2,0,1,3], target = 2

// i = 0
// sumUpperBound = 4
// left = 1, right = 3
// while loop:
// 0 + 3 < 4
// count += 3 - 1 -> count = 2
// left = 2
// 1 + 3 >= 4
// right = 2
// break