class Solution {
public:
    string reverseWords(string s) {
        int s_length = s.size();
        if (s_length == 0) return "";

        // " a bc " -> " cb a "
        // reverse the string
        reverse(s.begin(), s.end());

        // "cb aa "
        //      l
        //        r

        // remove the redundant empty space
        int read_ptr = 0, write_ptr = 0;
        while (read_ptr < s_length) {
            if (s[read_ptr] == ' ') {
                read_ptr++;
                continue;
            }

            // not the first word -> add empty space
            if (write_ptr != 0) {
                s[write_ptr++] = ' ';
            }

            while (read_ptr < s_length && s[read_ptr] != ' ') {
                s[write_ptr++] = s[read_ptr++];
            }
        }
        s.resize(write_ptr);

        // reverse each word
        int start = 0;
        int new_s_length = s.size();
        for (int end = 0; end <= new_s_length; end++) {
            if (end == new_s_length || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }
};

// class Solution {
// public:
//     string reverseWords(string s) {
//         int s_length = s.size();
//         if (s_length == 0) return "";

//         reverse(s.begin(), s.end());
        
//         string reversed = "";

//         int left = 0, right = 0;
//         while (right < s_length && s[right] == ' ') {
//             left++;
//             right++;
//         }

//         while (right < s_length) {
//             // increment right to the space after the reversed current word
//             while (right < s_length && s[right] != ' ') {
//                 right++;
//             }

//             // paste the reversed current word reversely to make the characters in order
//             for (int i = right - 1; i >= left; i--) {
//                 reversed += s[i];
//             }

//             // increment right to the start of the next word
//             while (right < s_length && s[right] == ' ') {
//                 right++;
//             }

//             // if right is less than the length of s, it means the next word exists
//             if (right < s_length) {
//                 reversed += ' ';
//             }

//             // assign right to left and start processing the next word
//             left = right;
//         }
//         return reversed;
//     }
// };

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

// WA: s = "  hello world  " -> output " world hello "
