// ## Understand

// What is the range of n?
// - 1 <= n <= 10^9
// What is the length of s
// - 1 <= s.length <= 1000


// ## Match

// A naive method is to iterate through 1 to n. For each value we iterate s to check if the binary representation of the value is in s.
// Another method is to find all binary representation in s. Then we check if there are some missing values in [1, n]. Sliding window
// can be applied to find all possible binary strings.


// ## Plan

// I will create an unordered_set visited to store the values found in s and between 1 and n. Then, I use sliding window on s. Every
// time, I fix the left pointer, initialize the right pointer at the position of left pointer, and shift it right until the window
// reaches length 32 or the last index of s. I will use a variable to store the accumulated values in this window, and update it
// to the visited if the value is between 1 and n.
// Lastly, if the size of visited is n, it means s contains all binary representation in the range of [1, n].


// ## Implementation

// WA on s = "0110", n = 3
// trace:
// s_length = 4
// visited = {}
// for loop:
//  left = 0
//  right = 0
//  current_val = 0
//  cond: 0-0+1<=32 && 0<4 -> T
//      current_val = 0
//      right = 1
//  cond: 1-0+1<=32 && 1<4 -> T
//      current_val = 0 + 1 = 1
//      visited = { 1 }
//      right = 2
//  cond: 2-0+1<=32 && 2<4 -> T
//      current_val = 2+1 = 3
//      visited = { 1, 3 }
//      right = 3
//  cond: 3-0+1<=32 && 3<4 -> T
//      current_val = 6 + 0 = 6 -> break
//  left = 1 -> the same as when left = 0
//  left = 2
//  right = 2
//  current_val = 0
//  cond: 2-2+1<=32 && 2<4 -> T
//      current_val = 1
//      right = 3
//  cond: 3-2+1<=32 && 3<4 -> T
//      current_val = 2 + 0 = 2
//  visited = { 1, 2, 3 }


class Solution {
public:
    bool queryString(string s, int n) {
        int s_length = s.size();

        unordered_set<int> visited;
        for (int left = 0; left < s_length; left++) {
            int right = left;
            int current_val = 0;
            while (right - left + 1 <= 32 && right < s_length) {
                current_val = (current_val << 1) + (s[right] - '0');
                if (current_val > n) {
                    break;
                }
                if (current_val >= 1 && current_val <= n) {
                    visited.insert(current_val);
                }
                right++;
            }
        }

        return visited.size() == n;
    }
};


// ## Review

// test case: s = "10", n = 1 -> true
// trace:
// s_length = 2
// > for loop
//  left = 0
//  right = 0, current_val = 0
//  cond: 0-0+1<=32 and 0<2 -> true
//      current_val = 1
//      visited = { 1 }
//      right = 1
//  cond: 2<=32 && 1<2 -> true
//      current_val = 2 + 0 = 2
//      visited = { 1, 2 }
//      right = 2
//  cond: true && 2 < 2 -> false
// size of visited = 2 <-> n = 2
// < returns true

// test case: s = "01", n = 2
// trace:
// s_length = 2
// > for loop
//  left = 0
//  right = 0, current_val = 0
//  cond: 0-0+1<=32 and 0<2 -> true
//      current_val = 0
//      right = 1
//  cond: 2<=32 && 1<2 -> true
//      current_val = 0 + 1 = 1
//      visited = { 1 }
//      right = 2
//  cond: true && 2 < 2 -> false
// size of visited = 1 <-> n = 2
// < returns false


// ## Evaluation

// Time: O(length of s * 32) = O(length of s)
// Space: O(length of s * 32) = O(length of s)


// ## Submit Error
// WA on s = "0110", n = 3
// trace:
// 