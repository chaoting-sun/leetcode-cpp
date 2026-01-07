class Solution {
public:
    string reverseWords(string s) {
        int s_length = s.size();
        if (s_length == 0) return "";

        // reverse the whole string
        reverse(s.begin(), s.end());

        // reverse each word + trim the empty space at two endpoint
        int left = 0, right = 0;
        string reversed_s = "";
        s.push_back(' ');

        while (right < s_length && s[right] == ' ') {
            right++;
        }
        left = right;

        while (right < s_length) {
            while (right < s_length && s[right] != ' ') {
                right++;
            }
            string substr_s = s.substr(left, right - left);
            reverse(substr_s.begin(), substr_s.end());
            reversed_s += substr_s + ' ';

            while (right < s_length && s[right] == ' ') {
                right++;
            }
            left = right;
        }

        reversed_s.pop_back();
        return reversed_s;
    }
};

// test case: s = " ab bc" -> "bc ab"
// trace:
// s = " ab bc "

// test case: s = " ab  bc " -> "bc ab"
//                 01234567
// trace:
// s_length = 8
// s = " cb  ba "
//      01234567
// left = 0, right = 0
// right = 1, left = 1
// right = 3, reversed_s = "bc ", right = 5, left = 5
// right = 5, reversed_s = "bc ab ", right = 8, left = 8
// reversed_s = "bc ab"
// < returns "bc ab"





// | olleh  world |
//          r
//          l
