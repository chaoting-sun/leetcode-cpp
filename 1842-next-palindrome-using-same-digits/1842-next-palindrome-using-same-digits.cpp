class Solution {
public:
    bool nextPermutation(string& s) {
        int n = s.size();
        if (n <= 1) return false;

        int pivot = n - 2;
        while (pivot >= 0 && s[pivot] >= s[pivot + 1]) {
            pivot--;
        }
        if (pivot == -1) return false;
        int nextGreaterIdx = n - 1;
        while (pivot < nextGreaterIdx && s[pivot] >= s[nextGreaterIdx]) {
            nextGreaterIdx--;
        }
        swap(s[pivot], s[nextGreaterIdx]);
        reverse(s.begin() + pivot + 1, s.end());
        return true;
    }

    string nextPalindrome(string num) {
        int n = num.size();
        int nHalf = n / 2;
        string sHalf = num.substr(0, nHalf);

        if (!nextPermutation(sHalf)) {
            return "";
        }

        string ans(sHalf);
        if (n % 2 == 1) {
            ans += num[nHalf];
        }
        
        string sHalfReversed(sHalf);
        reverse(sHalfReversed.begin(), sHalfReversed.end());
        ans += sHalfReversed;
        return ans;
    }
};
