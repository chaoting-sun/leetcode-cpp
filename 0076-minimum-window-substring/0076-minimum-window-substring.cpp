class Solution {
public:
    string minWindow(string s, string t) {
        int s_length = s.size();
        if (s_length == 0) return "";

        vector<int> t_char_freq(256);
        for (char ch: t) t_char_freq[ch]++;
        int to_satisfied_count = 0;
        for (int i = 0; i < 256; i++) {
            if (t_char_freq[i] > 0) {
                to_satisfied_count++;
            }
        }

        vector<int> widow_char_freq(256);
        int left = 0;
        int right = 0;
        int min_start_idx = -1;
        int min_length = INT_MAX;
        
        while (right < s_length) {
            widow_char_freq[s[right]]++;
            if (widow_char_freq[s[right]] == t_char_freq[s[right]]) {
                to_satisfied_count--;
            }

            while (to_satisfied_count == 0) {
                int current_length = right - left + 1;
                if (current_length < min_length) {
                    min_length = current_length;
                    min_start_idx = left;
                }
                if (widow_char_freq[s[left]] == t_char_freq[s[left]]) {
                    to_satisfied_count++;
                }
                widow_char_freq[s[left]]--;
                left++;
            }

            right++;
        }

        return min_length == INT_MAX ? "" : s.substr(min_start_idx, min_length);
    }
};

// test case
// s = 'abc', t = 'acc'
// t_char_freq = [1 0 2 ....]
// to_satisfied_count = 2
// l = 0, r = 0
// widow_char_freq[0] = 1 -> t_char_freq[0] == 1 -> to_satisfied_count = 1
// l = 0, r = 1
// widow_char_freq[1] = 1 -> t_char_freq[1] == 0
// l = 0, r = 2
// widow_char_freq[2] = 1 -> t_char_freq[2] == 2
// < min? no. -> ""

// s = 'abc', t = 'ac'
// t_char_freq = [1 0 1 ....]
// to_satisfied_count = 2
// l = 0, r = 0
// widow_char_freq[0] = 1 -> t_char_freq[0] == 1 -> to_satisfied_count = 1
// l = 0, r = 1
// widow_char_freq[1] = 1 -> t_char_freq[1] == 0
// l = 0, r = 2
// widow_char_freq[2] = 1 -> t_char_freq[2] == 1 -> to_satisfied_count = 0
// while loop
//  current_length = 3
//  min_length = 3
//  idx = 0
//  to_satisfied_count = 1
//  widow_char_freq[0] = 0
//  l = 1
// < min = s[0..2] = abc

// CE:
// for (int i = 0; i < 256; i++) {
//     if (t_char_freq[ch] > 0) {
//         to_satisfied_count++;
//     }
// }
// to
// for (int i = 0; i < 256; i++) {
//     if (t_char_freq[ch] > 0) {
//         to_satisfied_count++;
//     }
// }

// CE:
// return min_length == INT_MAX ? "" : s.substr(min_start_idx, current_length);
// to
// return min_length == INT_MAX ? "" : s.substr(min_start_idx, min_length);