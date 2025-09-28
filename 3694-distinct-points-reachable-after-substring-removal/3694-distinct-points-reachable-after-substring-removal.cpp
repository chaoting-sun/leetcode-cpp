class Solution {
public:
    // Approach: Prefix Sum + Bit Manipulation
    // Time: O(n)
    // Space: O(n)

    long long toKey(int x, int y) {
        return ((long long)x << 32) | (unsigned int)y;
    }

    int distinctPoints(string s, int k) {
        int n = s.size();
        if (n <= k) return 1;
        
        vector<int> prefX(n+1), prefY(n+1);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            prefX[i + 1] = prefX[i];
            prefY[i + 1] = prefY[i];

            if (c == 'R') prefX[i + 1]++;
            else if (c == 'L') prefX[i + 1]--;
            else if (c == 'U') prefY[i + 1]++;
            else if (c == 'D') prefY[i + 1]--;
        }

        int totalX = prefX[n];
        int totalY = prefY[n];

        unordered_set<long long> seen;
        for (int i = k; i <= n; i++) {
            int currX = totalX - prefX[i] + prefX[i - k];
            int currY = totalY - prefY[i] + prefY[i - k];
            seen.insert(toKey(currX, currY));
        }
        return seen.size();
    }
};
