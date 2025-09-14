// Approach: sliding window (fixed size)
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        int discardedCount = 0;
        unordered_map<int, int> typeFrequency;
        vector<bool> isDiscarded(n, false);
        
        for (int day = 0; day < n; day++) {
            int type = arrivals[day];
            typeFrequency[type]++;
            if (day - w >= 0 && !isDiscarded[day - w]) {
                typeFrequency[arrivals[day - w]]--;
            }
            if (typeFrequency[type] > m) {
                discardedCount++;
                typeFrequency[type]--;
                isDiscarded[day] = true;
            }
        }
        return discardedCount;
    }
};
  