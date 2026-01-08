class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        if (n == 0) return;
        
        reverse(s.begin(), s.end());
        int left = 0;
        for (int right = 0; right <= n; right++) {
            if (right == n || s[right] == ' ') {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
        }
    }
};