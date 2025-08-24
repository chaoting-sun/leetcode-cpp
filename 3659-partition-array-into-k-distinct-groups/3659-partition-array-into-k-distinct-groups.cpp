class Solution {
public:
    // Problem with "Very Bad Description": each group should have only k element and all are distinct

    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        unordered_map<int, int> counts;
        int max_count_required = n / k;
        int max_count = 0;

        for (auto v: nums) {
            counts[v]++;
            if (counts[v] > max_count) {
                max_count = counts[v];
            }
        }

        return max_count <= max_count_required;
    }
};
