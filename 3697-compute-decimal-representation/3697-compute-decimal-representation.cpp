class Solution {
public:
    // Approach: Math

    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long i = 1;
        while (n > 0) {
            int tmp = n % 10;
            if (tmp > 0) {
                ans.push_back((int)(tmp * i));
            }
            n /= 10;
            i *= 10;
        }

        int m = ans.size();
        for (int i = 0; i < m / 2; i++) swap(ans[i], ans[m - 1 - i]);
        return ans;
    }
};