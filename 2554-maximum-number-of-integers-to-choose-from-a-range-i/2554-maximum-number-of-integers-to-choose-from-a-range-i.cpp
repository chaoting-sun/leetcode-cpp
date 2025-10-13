class Solution {
public:
    // Approach: Hash Table
    // Time: O(n + m)
    // Space: O(m)

    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedMap(banned.begin(), banned.end());
        vector<int> available;
        for (int i = 1; i <= n; i++) {
            if (!bannedMap.count(i)) {
                available.push_back(i);
            }
        }
        int currentSum = 0;
        int m = available.size();
        for (int i = 0; i < m; i++) {
            currentSum += available[i];
            if (currentSum > maxSum) {
                return i;
            }
        }
        return m;
    }
};
