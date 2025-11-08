class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if (n == 0) return 0;
        if (n == 1) return tokens[0] <= power ? 1 : 0;

        sort(tokens.begin(), tokens.end());
        deque<int> dq;
        for (int token: tokens) dq.push_back(token);
        // left -> gain score, loss power, right -> loss score, gain power
        int maxScore = 0, currentScore = 0;
        while (!dq.empty()) {
            if (dq.front() <= power) {
                currentScore++;
                power -= dq.front();
                dq.pop_front();
            } else if (currentScore >= 1) {
                currentScore--;
                power += dq.back();
                dq.pop_back();
            } else {
                break;
            }
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};
