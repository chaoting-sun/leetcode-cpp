class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int, int> map{};

        for (int i = 0; i < nums.size(); i++) {
            int to_check = target - nums[i];
            auto it = map.find(to_check);
            if (it != map.end()) {
                ans[0] = it->second;
                ans[1] = i;
                return ans;
            }

            map.insert({ nums[i], i });
        }

        return ans;
    }
};