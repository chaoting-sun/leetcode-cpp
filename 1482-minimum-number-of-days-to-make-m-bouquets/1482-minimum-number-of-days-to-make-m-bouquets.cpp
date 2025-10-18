class Solution {
public:
    bool canMakeMBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int n = bloomDay.size();
        int left = 0, right = 0;
        int nBouquet = 0;
        while (left < n) {
            while (left < n && bloomDay[left] > day) left++;
            if (left == n) break;
            right = left;
            while (right < n - 1 && bloomDay[right + 1] <= day) right++; 
            nBouquet += (right - left + 1) / k;
            left = right + 1;
        }
        return nBouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (long long)bloomDay.size()) return -1;
        // find the first day such that we can make m bouquets
        int low = 1, high = 1e9;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMakeMBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};