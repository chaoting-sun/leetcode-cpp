class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> events(length + 1);
        for (auto& update: updates) {
            events[update[0]] += update[2];
            events[update[1]+1] -= update[2];
        }
        vector<int> ans(length);
        ans[0] = events[0];
        for (int i = 1; i < length; i++) {
            ans[i] = events[i] + ans[i - 1];
        }
        return ans;
    }
};