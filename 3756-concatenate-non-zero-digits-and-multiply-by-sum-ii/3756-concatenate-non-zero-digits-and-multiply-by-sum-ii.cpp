class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<int> pow(n + 1, 1);
        for (int i = 1; i <= n; i++) pow[i] = (pow[i - 1] * 10LL) % MOD;

        // sum -> prefixSum        
        // x -> prefixNum, prefixNoneZero
        // s[0..n-1] -> prefixSum[1..n]
        vector<int> prefixSum(n + 1);
        vector<int> prefixNum(n + 1);
        vector<int> prefixNoneZero(n + 1);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            prefixSum[i + 1] = prefixSum[i] + d;
            prefixNum[i + 1] = d > 0 ? ((prefixNum[i] * 10LL) % MOD + d) % MOD : prefixNum[i];
            prefixNoneZero[i + 1] = prefixNoneZero[i] + (d > 0 ? 1 : 0);
        }

        vector<int> ans;
        for (vector<int>& q: queries) {
            int l = q[0], r = q[1] + 1;
            int length = prefixNoneZero[r] - prefixNoneZero[l];
            int x = prefixNum[r] - (1LL * prefixNum[l] * pow[length]) % MOD + MOD;
            int intervalSum = prefixSum[r] - prefixSum[l];
            ans.push_back((1LL * x * intervalSum) % MOD);
        }
        return ans;
    }
};


