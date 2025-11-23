class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        string nStr = to_string(n);
        long long ans = 0;
        int s = 0;
        for (int i = 0; i < nStr.size(); i++) {
            if (nStr[i] == '0') continue;
            int digit = nStr[i] - '0';
            ans = ans * 10 + digit;
            s += digit;
        }
        return ans * s;
    }
};