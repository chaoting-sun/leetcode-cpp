class Solution {
public:
    // string maxSumOfSquares(int num, int sum) {
    //     string ans;
    //     for (int i = 0; i < num; i++) {
    //         if (sum >= 9) {
    //             ans += "9";
    //             sum -= 9;
    //         } else {
    //             ans += to_string(sum);
    //             sum = 0;
    //         }
    //     }
    //     return sum == 0 ? ans : "";
    // }

    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) return "";
        string ans(sum / 9, '9');
        if (sum % 9) ans += to_string(sum % 9);
        return ans + string(num - ans.size(), '0');
    }
};
