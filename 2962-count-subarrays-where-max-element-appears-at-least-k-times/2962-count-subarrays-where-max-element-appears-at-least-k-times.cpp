class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxV = nums[0];
        for (int i = 1; i < n; i++) maxV = max(maxV, nums[i]);

        long long ans = 0;
        int l = 0, r = 0;
        unordered_map<int, int> freq;

        while (r < n) {
            freq[nums[r]]++;
            
            while (freq[maxV] >= k) {
                ans += n - r;
                freq[nums[l]]--;
                l++;
            }
            r++;    
        }

        return ans;
    }
};

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();

//         int ans = 0;
//         int left = 0, right = 0;
//         priority_queue<int> pq;
//         unordered_map<int, int> freq;

//         while (right < n) {
//             if (!freq.count(nums[right])) {
//                 pq.push(nums[right]);
//             }
//             freq[nums[right]]++;
            
//             while (!freq.count(pq.top())) pq.pop();
//             if (freq[pq.top()] >= k)) {
//                 ans++;
//                 freq[nums[left]]--;
//                 if (freq[nums[left]] == 0) freq.erase(nums[left]);
//                 left++;
//             }

//             right++;    
//         }

//         return ans;
//     }
// };

// int left, right -> nums[left, ..., right]

// max heap = [value, ...] -> O(1) at least k times (count >= k)
// hash map = { value: count }
