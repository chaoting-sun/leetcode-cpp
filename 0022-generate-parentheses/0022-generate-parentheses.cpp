class Solution {
public:
    // Intuition: we need to enumerate all possibilities, so we use standard
    // Approach: Backtracking

    // Time: O(Cn * n)
    // Let's start from the case that all possibilities are valid.
    // The final string will be of length 2n.
    // In each recursion we copy the string (takes O(n) in worst case), and push back to ans (takes O(n)) -> O(n)
    // Each recursion calls itself twice, so there are O(2^n) function calls
    // So, the time complexity is O(n*2^n)
    // However, in this question, the valid ans is much fewer than all possibilities. We will skip all that are invalid.
    // The number of such valid combinations is call the Catalan number for n, written as Cn.
    // Cn ~ 4^n / n^1.5
    // So the total time complexity is # valid results * work per result = Cn * O(n)
    
    // Space: O(n^2) used by recursion; O(Cn * 2n) used by ans
    // O(n^2) - recursion depth * max size of each recursion = O(n) * O(n) = O(n^2)

    void backtrack(int nOpen, int nClose, int n, string& currentForm, vector<string>& ans) {
        // base case
        if (nOpen == n && nClose == n) {
            ans.push_back(currentForm);
            return;
        }

        if (nOpen < n) {
            currentForm.push_back('(');
            backtrack(nOpen + 1, nClose, n, currentForm, ans);
            currentForm.pop_back();
        }
        if (nOpen > nClose) {
            currentForm.push_back(')');
            backtrack(nOpen, nClose + 1, n, currentForm, ans);
            currentForm.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string currentForm;
        vector<string> ans;
    
        backtrack(0, 0, n, currentForm, ans);
        return ans;
    }

    // For the exercise next time

    // vector<string> generateParenthesis(int n) {

    // }
};