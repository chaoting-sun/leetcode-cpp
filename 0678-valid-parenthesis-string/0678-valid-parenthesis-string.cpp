class Solution {
public:
    // Approach: Greedy
    
    // We’re given a string of '(', ')', and '*', where '*' can be '(', ')',
    // or empty. We need to check if there’s any valid way to interpret it as
    // a balanced parentheses string
    
    // The tricky part is that '*' introduces multiple possibilities, and a
    // brute-force recursion would branch exponentially. We need something
    // linear and greedy

    // Instead of exploring all interpretations, we track the range of possible
    // unmatched open parentheses at each step. Specifically:
    // left_min = minimum possible open parentheses
    // left_max = maximum possible open parentheses
    // This range captures all the interpretations of '*' without explicitly branching.

    // For each character:
    // If it’s '(': both left_min and left_max increase.
    // If it’s ')': both decrease.
    // If it’s '*': it could act as '(', ')', or empty, so we do left_min-- and left_max++.
    // After each step:
    // If left_max goes negative, that means even the most optimistic case had too many ')', so it’s invalid.
    // If left_min goes negative, reset it to 0, since we can always treat some '*' as empty.”*

    // At the end, if left_min == 0, then it means there’s at least one valid interpretation that balances out. Otherwise, no.
    
    // This is essentially an interval greedy approach:
    // left_min = "pessimistic interpretation" (treat '*' as ')').
    // left_max = "optimistic interpretation" (treat '*' as '(').
    // By tracking both bounds, we cover all possibilities of how '*' can expand.
    // If at any point the "optimistic" case fails (left_max < 0), no interpretation can work.
    // If at the end, the "pessimistic" case still has unmatched '(' (left_min > 0), it means we couldn’t close all opens.

    // Time: O(n)
    // space: O(1)

    bool checkValidString(string s) {
        int left_max = 0, left_min = 0;

        for (char c: s) {
            if (c == '(') {
                left_max++;
                left_min++;
            } else if (c == ')') {
                left_max--;
                left_min--;
            } else {
                left_max++;
                left_min--;
            }
            if (left_max < 0) return false;
            if (left_min < 0) left_min = 0;
        }

        return left_min == 0;
    }
};
