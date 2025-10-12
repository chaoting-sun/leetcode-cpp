class Solution {
public:
    // int maximizeWin(vector<int>& prizePositions, int k) {
    //     int n = prizePositions.size();

    //     if (prizePositions[n - 1] - prizePositions[0] <= 2 * k)
    //         return n;
        
    //     vector<int> pre(n); // pre[i]: 左線段右端點不超過 prizePositions[i] 最多能 cover 到的 prize 數量
    //     vector<int> post(n); // post[i]: 右線段左端點不超過 prizePositions[i] 最多能 cover 到的 prize 數量
        
    //     int l = 0;
    //     pre[0] = 1;
    //     for (int r = 1; r < n; r++) {
    //         while (prizePositions[r] - prizePositions[l] > k)
    //             l++;
    //         pre[r] = max(pre[r - 1], r - l + 1);
    //     }
    //     int r = n - 1;
    //     post[n - 1] = 1;
    //     for (int l = n - 2; l >= 0; l--) {
    //         while (prizePositions[r] - prizePositions[l] > k)
    //             r--;
    //         post[l] = max(post[l + 1], r - l + 1);
    //     }
    //     int ans = 0;
    //     for (int i = 0; i < n - 1; i++) {
    //         ans = max(ans, pre[i] + post[i + 1]);
    //     }
    //     return ans;
    // }

    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> covered(n);
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r < n - 1 && prizePositions[r + 1] - prizePositions[l] <= k) {
                r++;
            }
            covered[l] = r - l + 1;
        }
        int ans = 0;
        int maxRightCovered = 0;
        r = n;
        for (int i = n - 1; i >= 0; i--) {
            while (prizePositions[r - 1] - prizePositions[i] > k) {
                r--;
                maxRightCovered = max(maxRightCovered, covered[r]);
            }
            ans = max(ans, covered[i] + maxRightCovered);
        }
        return ans;
    }
};