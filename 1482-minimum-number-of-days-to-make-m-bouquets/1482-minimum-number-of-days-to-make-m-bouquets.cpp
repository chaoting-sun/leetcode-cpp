// class Solution {
// public:
//     int getNumBouquets(vector<int>& bloomDay, int k, int day) {
//         int n = bloomDay.size();
//         int count = 0, nBouquet = 0;
//         for (int i = 0; i < n; i++) {
//             if (bloomDay[i] <= day) {
//                 count++;
//             } else {
//                 count = 0;
//             }
//             if (count == k) {
//                 nBouquet += 1;
//                 count = 0;
//             }
//         }
//         return nBouquet;
//     }

//     int minDays(vector<int>& bloomDay, int m, int k) {
//         if ((long long)m * k > (long long)bloomDay.size()) return -1;
//         // find the first day such that we can make m bouquets
//         int low = 1, high = 1e9;

//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (getNumBouquets(bloomDay, k, mid) >= m) {
//                 high = mid;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return high;
//     }
// };

class Solution {
public:
    int minDays(const std::vector<int>& bloomDay, int m, int k) {
        // 複製並排序天數
        std::vector<int> days = bloomDay;
        std::sort(days.begin(), days.end());

        int lo = -1;                      // 對 days 的索引做二分搜尋：不可行區間的右端
        int hi = static_cast<int>(days.size()); // 可行區間的左端（開區間），初始化為越界

        // 二分搜尋最小可行索引
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;      // 嘗試天數 = days[mid]
            int cnt = 0;                  // 已完成的束數
            int consecutive = 0;          // 連續可開花的朵數

            // 檢查在 days[mid] 這一天是否能做出 >= m 束
            for (int d : bloomDay) {
                if (d <= days[mid]) {
                    if (++consecutive == k) {
                        ++cnt;
                        consecutive = 0;  // 一束完成後歸零
                    }
                } else {
                    consecutive = 0;      // 中斷連續
                }
            }

            if (cnt >= m) {
                hi = mid;                 // 可以達成，縮小右邊界
            } else {
                lo = mid;                 // 無法達成，提升左邊界
            }
        }

        if (hi == static_cast<int>(days.size())) return -1; // 完全不可行
        return days[hi];                                     // 最小可行天數
    }
};