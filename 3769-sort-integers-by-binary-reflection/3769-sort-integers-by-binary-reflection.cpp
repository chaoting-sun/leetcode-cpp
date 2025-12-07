class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<int> reversed(n);

        for (int i = 0; i < n; i++) {
            int res = 0;
            int curr = nums[i];
            while (curr > 0) {
                res = res << 1 | (curr & 1);
                curr >>= 1;
            }
            reversed[i] = res;
        }

        vector<pair<int,int>> combined(n);
        for (int i = 0; i < n; i++) {
            combined[i] = { nums[i], reversed[i] };
        }
        sort(combined.begin(), combined.end(), [](pair<int,int>& p1, pair<int,int>& p2) {
            if (p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        });

        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = combined[i].first;
        return ans;
    }
};