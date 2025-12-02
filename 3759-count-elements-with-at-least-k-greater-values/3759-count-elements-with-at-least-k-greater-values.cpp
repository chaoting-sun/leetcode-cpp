// class Solution {
// public:
//     int countElements(vector<int>& nums, int k) {
//         int n = nums.size();
//         map<int, int> freq;
//         for (int n: nums) freq[n]++;

//         vector<pair<int,int>> p;
//         for (auto [v, f]: freq) {
//             p.push_back({ v, f });
//         }
//         reverse(p.begin(), p.end());

//         int ans = 0;
//         int largerCount = 0;
//         for (int i = 0; i < (int)p.size(); i++) {
//             if (i == 0) {
//             } else {
//                 if (p[i - 1].first > p[i].first) {
//                     largerCount += p[i - 1].second;
//                 }
//             }
//             if (largerCount >= k) {
//                 ans += p[i].second;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n  = nums.size();
        if (k == 0) return n;

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
        });

        int ans = 0;
        int kthValue = nums[k - 1];
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] < kthValue) {
                ans++;
            }
        }
        return ans;
    }
};