class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> received(n);
        int i = 1;
        int pos = 0;
        received[pos] = 1;
        while (true) {
            int nextPos = (pos + k * i) % n;
            received[nextPos]++;

            if (received[nextPos] == 2) break;

            pos = nextPos;
            i++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (received[i] == 0) ans.push_back(i + 1);
        }
        return ans;
    }
};