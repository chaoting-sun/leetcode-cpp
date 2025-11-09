class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if (n == 0) return 0;
        if (n == 1) return tokens[0] <= power ? 1 : 0;

        sort(tokens.begin(), tokens.end());
        // left -> gain score, loss power, right -> loss score, gain power
        int maxScore = 0, currentScore = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (tokens[left] <= power) {
                currentScore++;
                power -= tokens[left];
                left++;
            } else if (currentScore >= 1) {
                currentScore--;
                power += tokens[right];
                right--;
            } else {
                break;
            }
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};
