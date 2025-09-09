class Solution {
public:
    // Approach: Hash Map
    // Time: O(n)
    // Space: O(n)

    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string, int> value_counts;// width/gcd,height/gcd: counts
        long long count = 0;
        for (auto& rec: rectangles) {
            int _gcd = gcd(rec[0], rec[1]);
            int new_height = rec[0] / _gcd;
            int new_width = rec[1] / _gcd;

            string key = to_string(new_height) + "," + to_string(new_width);
            if (value_counts.count(key)) count += value_counts[key];
            value_counts[key]++;
        }
        return count;
    }
};
