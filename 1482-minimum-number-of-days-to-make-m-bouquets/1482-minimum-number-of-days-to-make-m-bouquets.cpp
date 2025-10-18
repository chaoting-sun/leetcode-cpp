class Solution {
public:
    int getNumBouquets(vector<int>& bloomDay, int k, int day) {
        int n = bloomDay.size();
        int count = 0, nBouquet = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                count = 0;
            }
            if (count == k) {
                nBouquet += 1;
                count = 0;
            }
        }
        return nBouquet;
    }

    // int minDays(vector<int>& bloomDay, int m, int k) {
    //     if ((long long)m * k > (long long)bloomDay.size()) return -1;
    //     // find the first day such that we can make m bouquets
    //     int low = 1, high = 1e9;

    //     while (low < high) {
    //         int mid = low + (high - low) / 2;
    //         if (getNumBouquets(bloomDay, k, mid) >= m) {
    //             high = mid;
    //         } else {
    //             low = mid + 1;
    //         }
    //     }
    //     return high;
    // }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        vector<int> days(n);
        for (int i = 0; i < n; i++) days[i] = bloomDay[i];
        sort(days.begin(), days.end());
        int low = -1, high = n;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (getNumBouquets(bloomDay, k, days[mid]) >= m) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (high == n || high == -1) return -1;
        return days[high];
    }
};