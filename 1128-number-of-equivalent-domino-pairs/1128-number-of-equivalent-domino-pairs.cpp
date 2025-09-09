class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> pair_counts;
        for (vector<int>& domino: dominoes) {
            int first = domino[0], second = domino[1];
            if (second < first) swap(first, second);
            string key = to_string(first) + "," + to_string(second);
            pair_counts[key]++;
        }
        int count = 0;
        for (auto [_, current_count]: pair_counts) {
            count += current_count * (current_count - 1) / 2;
        }
        return count;
    }
};