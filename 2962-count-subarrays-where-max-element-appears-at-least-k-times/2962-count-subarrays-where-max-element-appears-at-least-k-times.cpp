class Solution {
public:
    // long long countSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     int maxV = nums[0];
    //     for (int i = 1; i < n; i++) maxV = max(maxV, nums[i]);

    //     long long ans = 0;
    //     int l = 0, r = 0;
    //     int count = 0;

    //     while (r < n) {
    //         if (nums[r] == maxV) count++;
    //         while (count >= k) {
    //             ans += n - r;
    //             if (nums[l] == maxV) count--;
    //             l++;
    //         }
    //         r++;    
    //     }

    //     return ans;
    // }

    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxV = nums[0];
        for (int i = 1; i < n; i++) maxV = max(maxV, nums[i]);

        long long ans = 0;
        int l = 0, r = 0;
        queue<int> q;

        while (r < n) {
            if (nums[r] == maxV) {
                q.push(r);
            }
            while (q.size() >= k) {
                ans += (long long)(q.front() - l + 1) * (n - r);
                l = q.front() + 1;
                q.pop();
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
