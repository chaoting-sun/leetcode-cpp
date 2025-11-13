class Solution {
public:
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int n = nums.size();
    //     unordered_map<int, int> prefixCount;
    //     prefixCount.reserve(n);
    //     prefixCount[0] = 1;

    //     int ans = 0;
    //     int prefix = 0;

    //     for (int i = 0; i < n; ++i) {
    //         prefix += nums[i];
    //         ans += prefixCount[prefix - goal];
    //         prefixCount[prefix]++;
    //     }
    //     return ans;
    // }

    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int n = nums.size();
    //     int ans = 0;
    //     int oneCount = 0;
    //     int left = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] == 1) oneCount++;
    //         while (oneCount > goal && left < i) {
    //             if (nums[left] == 1) oneCount--;
    //             left++;
    //         }
    //         if (oneCount == goal) ans++;
    //     }
    //     while (oneCount == goal && left + 1 < n) {
    //         if (nums[left + 1] == 0) ans++;
    //         left++;
    //     }
        
    //     return ans;
    // }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int>& nums, int most) {
        if (most < 0) return 0;
        int count = 0;
        int total = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            total += nums[right];
            while (left <= right && total > most) {
                total -= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};
// [1,0,1,0,1] most = 2
// right = 0 total = 1 count = 1
// right = 1 total = 1 count = 2
// right = 2 total = 2 count = 2
