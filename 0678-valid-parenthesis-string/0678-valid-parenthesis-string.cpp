class Solution {
public:
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
