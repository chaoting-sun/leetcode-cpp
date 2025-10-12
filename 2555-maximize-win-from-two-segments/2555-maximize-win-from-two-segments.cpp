class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();

        if (prizePositions[n - 1] - prizePositions[0] <= 2 * k)
            return n;
        
        vector<int> pre(n), post(n);
        int l = 0;
        pre[0] = 1;
        for (int r = 1; r < n; r++) {
            while (prizePositions[r] - prizePositions[l] > k)
                l++;
            pre[r] = max(pre[r - 1], r - l + 1);
        }
        int r = n - 1;
        post[n - 1] = 1;
        for (int l = n - 2; l >= 0; l--) {
            while (prizePositions[r] - prizePositions[l] > k)
                r--;
            post[l] = max(post[l + 1], r - l + 1);
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, pre[i] + post[i + 1]);
        }
        return ans;
    }
};