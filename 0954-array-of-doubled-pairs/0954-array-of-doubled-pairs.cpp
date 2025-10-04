class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        unordered_map<int, int> counts;
        for (int val: arr) counts[val]++;

        for (int i = 0; i < arr.size(); i++) {
            int a = arr[i], b = 2 * arr[i];
            if (counts[a] == 0) continue;
            if (!counts.count(b) || counts[b] == 0) {
                return false;
            }
            counts[a]--;
            counts[b]--;
        }

        return true;
    }
};
