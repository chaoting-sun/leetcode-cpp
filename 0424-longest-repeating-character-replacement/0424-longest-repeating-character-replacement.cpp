class Solution {
public:
    int characterReplacement(string s, int k) {
        int s_length = s.size();
        if (s_length == 0) return 0;

        vector<int> char_count(26);
        int left = 0;
        int right = 0;
        int max_char_count = 0;
        int max_length = 0;

        while (right < s_length) {
            char ch = s[right];
            char_count[ch - 'A']++;

            max_char_count = max(max_char_count, char_count[ch - 'A']);

            while ((right - left + 1) - max_char_count > k) {
                char_count[s[left] - 'A']--;
                left++;
            }
            max_length = max(max_length, right - left + 1);
            right++;
        }

        return max_length;
    }
};


// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int s_length = s.size();
//         if (s_length == 0) return 0;

//         // only process the characters in s
//         vector<bool> seen(26, false);
//         for (char c: s) seen[c - 'A'] = true;

//         int max_length = 0;

//         for (int c = 0; c < 26; c++) {
//             if (!seen[c]) continue;

//             int left = 0;
//             int right = 0;
//             int char_count = 0;
            
//             while (right < s_length) {
//                 if (s[right] - 'A' == c) {
//                     char_count++;
//                 }
                
//                 while ((right - left + 1) - char_count > k) {
//                     if (s[left] - 'A' == c) {
//                         char_count--;
//                     }
//                     left++;
//                 }

//                 // the window is valid now
//                 max_length = max(max_length, right - left + 1);
                
//                 right++;
//             }
//         }
//         return max_length;
//     }
// };

// happy path
// s = 'AAB' k = 1
// for loop: c = 0, 1
// c = 0
//  l   r   count   size    max
//  0   0   1       1       1
//  0   1   2       2       2
//  0   2   2       3       3
// c = 1
//  l   r   count   size    max action
//  0   0   0       1       3
//  0   1   0       2(2>1)      increment l
//  1   1   0       1       3
//  1   2   1       2       3
//  < returns 3

// base case
// s = 'A' k = 0
// for loop: c = 0
// c = 0
//  l   r   count   size    max
//  0   0   1       1       1
//  < returns 3

// trap case
// s = 'AAB' k = 0
// for loop: c = 0, 1
// c = 0
//  l   r   count   size    max action
//  0   0   1       1       1
//  0   1   2       2       2
//  0   2   2       3(1>0)      increment l
//  1   2   1       2(1>0)      increment l
//  2   2   0       1(1>0)      increment l
//  3   2   0       0(0>0)  2
//  c = 1
//  l   r   count   size    max action
//  0   0   0       1(1>0)      increment l
//  1   0   0       0(0>0)  2
//  1   1   1       1(1>0)      increment l
//  2   1   0       0(0>0)  2
//  2   2   1       1       2
// < returns 2