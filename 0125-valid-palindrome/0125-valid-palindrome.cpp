class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            if (!isalnum(s[r])) {
                r--;
                continue;
            }
            int lChar = tolower(s[l]);
            int rChar = tolower(s[r]);
            if (lChar != rChar) return false;
            l++;
            r--;
        }
        return true;
    }
};