class Solution {
public:
    string reverseWords(string s) {
        int s_length = s.size();
        if (s_length == 0) return "";

        reverse(s.begin(), s.end());

        int write = 0;
        int read = 0;

        while (read < s_length) {
            if (s[read] == ' ') {
                read++;
                continue;
            }

            if (write > 0) {
                s[write] = ' ';
                write++;
            }

            while (read < s_length && s[read] != ' ') {
                s[write++] = s[read++];
            }
        }

        s.resize(write);

        int left = 0;
        for (int right = 0; right <= s_length; right++) {
            if (right == s_length || s[right] == ' ') {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
        }
        return s;
    }
};

// test case: s = " ab bc" -> "bc ab"
// trace:
// s = " ab bc "



// | olleh  world |
//       r
//  l
