class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(0);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            level++;
            while (sz--) {
                int curr = q.front();
                q.pop();
                int left = n - curr;
                for (int i = 1; i * i <= left; i++) {
                    int squared = i * i;
                    if (squared == left) return level;
                    q.push(curr + squared);
                }
            }
        }
        return -1;
    }
};