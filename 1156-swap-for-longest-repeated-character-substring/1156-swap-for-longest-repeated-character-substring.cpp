// ## Understand

// Q: How long is the text? Can text be empty?
// A: 1 <= text.length <= 2 * 10^4

// Q: What kind of characters does text contain?
// A: text consists of lowercase english characters only


// ## Match

// The bruteforce method will be finding all possible pairs. We swap each pair and calculate the longest substring
// but this takes O(N^2) time to find pairs, and O(N) time to compute the longest substring, totally costing O(N^3)
// However, there is a strong constraint that the text consists only of lowercase english characters, only 26
// distinct characters. We can check the longest substring we can achieve one by one. There are two possible conditions
// to obtain the longest substring.
// One is to extend the substring by 1 character if there exist one somewhere.
// for example, "aa [][] a" can be swapped to "aaa [][]"
// Second is to merge two substrings with one gap. we either swap the gap character with some distant same character or
// the endpoint of one of the subtring
// for example, "aa [] a [][] a" can be swapped to "aaaa [][][]". "aa [] a [][]" can be swapped to "aaa [][]".

// ## Plan

// My plan is,
// I count the frequency of each characters, storing in a frequency map.
// Then, I create a global variable max_substr_length initialized to 0.
// for each time I focus on one distinct character. I iterate through text, creating a compressed representation
// of text like [(a, 3), ('*', 1), ...]. '*' represents the other characters, storing in the variable compressed_text.
// Then, I iterate through compressed_text, I update max_substr_length with 3 conditions:
// 1. for current character. no swap happened. then the length is the element count
// 2. for current character. I swap the neighbor character with the current character in some distant position. If
// the frequency of the current character is larger than the current count, we can do this
// 3. for other character. if it is the gap between two block of current characters, I merge the two blocks


// Implementation

class Solution {
public:
    int maxRepOpt1(string text) {
        int text_length = text.size();

        // firstly, I create a frequency map to store the count of all characters in text
        vector<int> freq_count(26);
        for (int i = 0; i < text_length; i++) {
            freq_count[text[i] - 'a']++;
        }
        
        // then, I build the compressed representation of text, dividing the text into smaller chunks
        // here, I store the character using integer for convenience
        vector<pair<int, int>> compressed;
        for (int i = 0; i < text_length; i++) {
            // for the current element to be processed, I combine it with the previous chunk if they are
            // the same character. This helps me calculate the longest substring
            if (!compressed.empty() && compressed.back().first == text[i] - 'a') {
                compressed.back().second++;
            } else {
                // if they are not the same, I create a new chunk for the the current character
                compressed.push_back({ text[i] - 'a', 1 });
            }
        }
        
        // I use the global variable to track the longest substring as the answer
        int longest_substring_length = 0;
        int compressed_length = compressed.size();

        // then, for each character, I try to build the longest substring using the compressed representation
        for (int c = 0; c < 26; c++) {
            // when the character is not in text, it won't do any contribution
            if (freq_count[c] == 0) continue;

            for (int i = 0; i < compressed_length; i++) {
                // There are two cases
                // I firstly handle the case that the character of the current chunks are the same as the the current character
                if (compressed[i].first == c) {
                    // If there are other same characters not in this chunk, I can swap to increment the length of the chunk
                    int final_length = freq_count[c] > compressed[i].second ? compressed[i].second + 1 : compressed[i].second;
                    longest_substring_length = max(longest_substring_length, final_length);
                } else {
                    // if the character in this chunk is not the same as the current character,
                    // we can merge its both-side neighbors if they are the current character
                    if (i > 0 && i < compressed_length - 1 && compressed[i - 1].first == c && compressed[i + 1].first == c && compressed[i].second == 1) {
                        // they can at least merge using a character in one's end point
                        int merged_length = compressed[i - 1].second + compressed[i + 1].second;
                        // however, if there still another same characters not in these chunks, the merged length can increment by 1
                        int final_length = freq_count[c] > merged_length ? merged_length + 1 : merged_length;
                        longest_substring_length = max(longest_substring_length, final_length);
                    }
                }
            }
        }

        return longest_substring_length;
    }
};


// ## Review

// happy path: aabba
// trace:
// freq_count = [3, 2, ...]. index 0 increments by three times. index 1 increments by twice
// compressed = [(0, 2), (1, 2), (0, 1)].
// i = 0, text[0] - 'a' is 0. compressed is empty. create one element
// i = 1, text[0] - 'a' is 0. the last element is 0. increment the count
// i = 2, text[0] - 'b' is 1. push new element
// i = 3, text[0] - 'b' is 1. increment the the count of the last element
// i = 4, text[0] - 'a' is 0. push new element

// compressed_length = 3
// for those character not 'a' or 'b', they will not be computed, so we focus on the two characters
// c = 0
//  i   merged   final   longest
//  -----------------------------
//  0            3       3
//  1   3        3       3
//  2            2       3
// c = 1
//  i   merged   final   longest
//  -----------------------------
//  0            0       3
//  1            2       3
//  0            0       3
// return 3

// base case: a
// freq_count[0] = 1
// compressed = [(0,1)]
// c = 0
//  i   merged   final   longest
//  -----------------------------
//  0            1       1
// return 1


// ## Evaluation

// Time: the most time costing computation is in the nested loop, which at most cost O(26*(length of text))
// Space: the variable compressed will take at most O(length of text)


// ## Submit Error

// WA:
// if (i > 0 && i < compressed_length - 1 && compressed[i - 1].first == c && compressed[i + 1].first == c)
// to
// if (i > 0 && i < compressed_length - 1 && compressed[i - 1].first == c && compressed[i + 1].first == c && compressed[i].second == 1)