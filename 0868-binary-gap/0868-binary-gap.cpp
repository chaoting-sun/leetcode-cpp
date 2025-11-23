class Solution {
public:
    int binaryGap(int n) {
        if (n == 0) return 0;
        
        int ans = 0;
        while ((n & 1) == 0) {
            n >>= 1;
        }
        int dist = 0;
        n >>= 1;
        while (n > 0) {
            dist++;
            int bit = n & 1;
            if (bit) {
                ans = max(ans, dist);
                dist = 0;
            }
            n >>= 1;
        }
        return ans;
    }
};
