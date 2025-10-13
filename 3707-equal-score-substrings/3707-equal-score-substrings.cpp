class Solution {
public:
    // Time: O(n)
    // Space: O(1)

    bool scoreBalance(string s) {
        int totalScore = 0;
        for (char c: s) {
            totalScore += (c - 'a') + 1;
        }
        int currentScore = 0;
        for (char c: s) {
            currentScore += (c - 'a') + 1;
            if (currentScore * 2 == totalScore) {
                return true;
            }
        }
        return false;
    }
};