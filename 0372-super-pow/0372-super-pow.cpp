using ll = long long;

class Solution {
public:
    int myPow(ll base, ll exp, ll mod) {
        int res = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        const int mod = 1337;

        if (b.empty()) {
            return 1;
        }
        
        int last = b.back();
        b.pop_back();

        ll ans = myPow(a, last, mod) * superPow(myPow(a, 10, mod), b);
        ans %= mod;
        return (int)ans;
    }
};

// a^[...prefix, last] = a^(prefix * 10) * a^last = (a^10)^prefix * a^last;