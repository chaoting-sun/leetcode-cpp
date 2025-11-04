class Solution {
public:
    string nextPalindrome(string num) {
        int n = num.size(), half = n / 2;
        string ans(num);
        int pivot = n % 2 == 1 ? half + 2 : half + 1;
        while (pivot < n && ans[pivot - 1] <= ans[pivot]) {
            pivot++;
        }
        if (pivot >= n) return "";
        int prevGreaterIdx = n % 2 == 1 ? half + 1 : half;
        while (prevGreaterIdx < pivot && ans[prevGreaterIdx] <= ans[pivot]) {
            prevGreaterIdx++;
        }
        swap(ans[prevGreaterIdx], ans[pivot]);
        if (n % 2 == 1) {
            reverse(ans.begin() + half + 1, ans.begin() + pivot);
        } else {
            reverse(ans.begin() + half, ans.begin() + pivot);
        }
        for (int i = 0; i < half; i++) {
            ans[i] = ans[n - 1 - i];
        }
        return ans;
    }
};

// 121
// 31435 5 53413

// 31455 3 55413
// 31453 5 35413

// 131131

// 1212
// half = 2
// pivot = 3
// prevGreaterIdx = 2
// reverse: 2~2

// 0 1 2 3 4  5 6 7 8 9
// 1 3 2 2 1  3 2 1 1 2
// n = 10
// half = 5
// pivot = 9
// prevGreaterIdx = 6

// 5 4 4 5 5 4 4 5