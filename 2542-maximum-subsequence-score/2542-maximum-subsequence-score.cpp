using ll = long long;
using PI2 = pair<int,int>;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<PI2> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i].first = nums1[i];
            nums[i].second = nums2[i];
        }
        
        sort(nums.begin(), nums.end(), [](PI2& a, PI2& b) {
            return a.second > b.second;
        });

        ll ans = 0;
        ll nums2sum = 0;
        priority_queue<int, vector<int>, greater<>> pq; // minheap: nums1[i]
        for (int i = 0; i < n; i++) {
            pq.push(nums[i].first);
            nums2sum += nums[i].first;
            if (pq.size() > k) {
                nums2sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = max(ans, (ll)(nums2sum * nums[i].second));
            }
        }
        return ans;
    }
};

// [3,1,3,2]
// [1,2,3,4]


// [5,6,7,9,10]
// [2,1,4,1,3]