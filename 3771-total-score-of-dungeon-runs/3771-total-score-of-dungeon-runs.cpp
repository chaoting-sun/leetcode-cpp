class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long> suffixDamage(n);
        suffixDamage[n - 1] = damage[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixDamage[i] = suffixDamage[i + 1] + damage[i];
        }

        long long ans = 0;
        int shift = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int left = 0, right = i + 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (suffixDamage[mid] - shift + requirement[i] <= hp) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            if (right <= i) ans += i - right + 1;
            shift += damage[i];
        }
        return ans;
    }
};

