class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> value_counts; // value: count

        for (int value: nums) value_counts[value]++;
        int count = 0;
        for (auto [_, current_count]: value_counts) {
            count += current_count * (current_count - 1) / 2;
        }
        return count;
    }
};