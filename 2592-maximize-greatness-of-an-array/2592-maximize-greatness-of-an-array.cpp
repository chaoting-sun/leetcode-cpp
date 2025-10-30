// class Solution {
// public:
//     int maximizeGreatness(vector<int>& nums) {
//         int ans = 0;
//         sort(nums.begin(), nums.end());
//         int i = 0;
//         for (int n: nums) {
//             if (n > nums[i]) {
//                 ans++;
//                 i++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                ans++;
                i--;
            }
        }
        return ans;
    }
};

