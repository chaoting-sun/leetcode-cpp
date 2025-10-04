class Solution {
public:
    // Approach: Greedy
    // Time: O(n*logn)
    // Space: O(n)

    // bool canReorderDoubled(vector<int>& arr) {
    //     sort(arr.begin(), arr.end(), [](int a, int b) {
    //         return abs(a) < abs(b);
    //     });
    //     unordered_map<int, int> counts;
    //     for (int val: arr) counts[val]++;

    //     for (int i = 0; i < arr.size(); i++) {
    //         int a = arr[i], b = 2 * arr[i];
    //         if (counts[a] == 0) continue;
    //         if (!counts.count(b) || counts[b] == 0) {
    //             return false;
    //         }
    //         counts[a]--;
    //         counts[b]--;
    //     }

    //     return true;
    // }

    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> counts;
        for (int val: arr) counts[val]++;
        for (auto& [val, currentCount]: counts) {
            if (currentCount == 0) continue;
            if (val >= 0) {
                int want = 2 * val;
                if (!counts.count(want) || currentCount > counts[want]) return false;
                counts[want] -= currentCount;
            } else {
                if (val % 2 != 0) return false;
                int want = val / 2;
                if (!counts.count(want) || currentCount > counts[want]) return false;
                counts[want] -= currentCount;
            }
        }
        return true;
    }
};
