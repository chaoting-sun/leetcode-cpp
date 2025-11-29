class Solution {
public:
    // int strStr(string haystack, string needle) {
    //     int n = haystack.size(), m = needle.size();
    //     if (n < m) return -1;

    //     for (int i = 0; i <= n - m; i++) {
    //         string current = haystack.substr(i, m);
    //         if (current == needle) return i;
    //     }
    //     return -1;
    // }

    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (n < m) return -1;

        const long long BASE = 26;
        const long long MOD = 1e9 + 7;

        long long pow = 1;
        for (int i = 0; i < m - 1; i++) {
            pow = (pow * BASE) % MOD;
        }

        long long hash = 0;
        long long target = 0;
        for (int i = 0; i < m; i++) {
            hash = (hash * BASE + (haystack[i] - 'a')) % MOD;
            target = (target * BASE + (needle[i] - 'a')) % MOD;
        }
        if (hash == target && haystack.substr(0, m) == needle) {
            return 0;
        }

        for (int i = 1; i <= n - m; i++) {
            int toRemove = haystack[i - 1] - 'a';
            long long left = (hash - toRemove * pow % MOD + MOD) % MOD;
            
            int toAdd = haystack[i + m - 1] - 'a';
            hash = (left * BASE + toAdd) % MOD;
            
            if (hash == target && haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};