class Solution {
public:
    // string toKey(vector<int>& counts) {
    //     int upDown = counts[0] - counts[1];
    //     int leftRight = counts[2] - counts[3];
    //     return to_string(upDown) + "," + to_string(leftRight);
    // }

    // void addCount(vector<int>& counts, char c) {
    //     if (c == 'U') counts[0]++;
    //     if (c == 'D') counts[1]++;
    //     if (c == 'L') counts[2]++;
    //     if (c == 'R') counts[3]++;
    // }

    // void subtractCount(vector<int>& counts, char c) {
    //     if (c == 'U') counts[0]--;
    //     if (c == 'D') counts[1]--;
    //     if (c == 'L') counts[2]--;
    //     if (c == 'R') counts[3]--;
    // }
    
    // int distinctPoints(string s, int k) {
    //     int n = s.size();
    //     if (n <= k) return 1;
        
    //     unordered_set<string> pattern; // ex: 4,4,3,2
    //     vector<int> counts(4); // U: 0, D: 1, L: 2, R: 3
        
    //     for (int i = k; i < n; i++) {
    //         addCount(counts, s[i]);
    //     }
    //     pattern.insert(toKey(counts));

    //     for (int i = k; i < n; i++) {
    //         subtractCount(counts, s[i]);
    //         addCount(counts, s[i - k]);
    //         pattern.insert(toKey(counts));
    //     }
    //     return pattern.size();
    // }


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

// LUL
// prefX = [0,-1,-1,-2]
// prefY = [0, 0, 1, 1]
// totalX = -2, totalY = 1

// i = 1
// currX = -2 - (-1) + 0 = -1
// currY = 1 - 0 + 0 = 1
// i = 2
// currX = -2 - (-1) + (-1) = -2
// currY = 1 - 1 + 0 = 0
// i = 3
// currX = -2 - (-2) + (-1) = -1
// currY = 1 - 1 + 0 = 0