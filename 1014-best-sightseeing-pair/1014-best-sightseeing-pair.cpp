class Solution {
public:
    // Approach: 
    // values[i] + values[j] + i - j = (values[i] + i) + (values[j] - j)
    // so we maintain the max value of (values[i] + i) from left to right
    // and compute the maintain the max score

    int maxScoreSightseeingPair(vector<int>& values) {
        int max_i_score = values[0] + 0; // values[i] + i
        int max_score = INT_MIN;
        for (int i = 1; i < (int)values.size(); i++) {
            max_score = max(max_score, max_i_score + values[i] - i);
            max_i_score = max(max_i_score, values[i] + i);
        }
        return max_score;
    }
};