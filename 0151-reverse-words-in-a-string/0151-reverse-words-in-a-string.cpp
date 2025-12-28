class Solution {
public:
    string reverseWords(string s) {
        int s_length = s.size();
        if (s_length == 0) return "";

        reverse(s.begin(), s.end());
        
        string reversed = "";

        int left = 0, right = 0;
        while (right < s_length && s[right] == ' ') {
            left++;
            right++;
        }

        while (right < s_length) {
            while (right < s_length && s[right] != ' ') {
                right++;
            }

            for (int i = right - 1; i >= left; i--) {
                reversed += s[i];
            }

            while (right < s_length && s[right] == ' ') {
                right++;
            }

            if (right < s_length) {
                reversed += ' ';
            }

            left = right;
        }
        return reversed;
    }
};

// happy path: s = "ab bc" -> output = "bc ab"
// trace:
// s_length = 5
// reverse s -> s = "cb ba"
// l    r   r'  reversed    r'' l'
// 0    0   2   "bc "       3   3
// 3    3   5   "bc ab"     5   5
// < returns "bc ab"
// base case:
// s = "a"
// reverse s -> a
// l    r   r'  reversed    r'' l'
// 0    0   1   "a"
// 
// < returns a
// trap case: s = "ab  c" -> output = "c ab"
// trace:
// s_length = 5
// reverse s -> s = "c  ba"
// l    r   r' reversed r'  l'
// 0    0   2  "c "     3   3
// 3    3   5  "c ab"   5   5 -> break
// < returns "c ab"

// WA: s = "  hello world  "
