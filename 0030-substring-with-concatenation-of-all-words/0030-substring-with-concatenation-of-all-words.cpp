// words = ['ab', 'bc'], s = 'abbcd'
//                            01234
// trace:
// required words = { 'ab', 'bc' }
// for loop: r = 0, 2
//  r = 0
//  curr = ab
//  c

class Solution {
private:
    void findStartingIndices(const string& s, const unordered_map<string_view, int>& required_words, int start, vector<int>& starting_indices, int word_len, int total_words) {
        int s_length = s.size();
        unordered_map<string_view, int> seen_words;
        int count = 0;
        int left = start;

        for (int right = start; right < s_length; right += word_len) {
            string_view current = string_view(s).substr(right, word_len);
            if (!required_words.count(current)) {
                left = right + word_len;
                count = 0;
                seen_words.clear();
                continue;
            }

            seen_words[current]++;
            count++;

            while (seen_words[current] > required_words.at(current)) {
                string_view previous = string_view(s).substr(left, word_len);
                count--;
                seen_words[previous]--;
                left += word_len;
            }

            if (count == total_words) {
                starting_indices.push_back(left);
                string_view previous = string_view(s).substr(left, word_len);
                seen_words[previous]--;
                count--;
                left += word_len;
            }
        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_length = s.size();
        if (s_length == 0) return {};

        unordered_map<string_view, int> required_words;
        int total_words = 0;
        for (const string& word: words) {
            total_words++;
            required_words[word]++;
        }
        
        vector<int> starting_indices;
        int word_length = words[0].size();
        for (int i = 0; i < word_length; i++) {
            findStartingIndices(s, required_words, i, starting_indices, word_length, total_words);
        }
        return starting_indices;
    }
};

// s = 'abbckab' words = ['ab', 'bc']
// required_words = { 'ab', 'bc' }
// s = 'abbckab'
//      0123456
//          r
//        l
// r=0
// seen_words = { 'ab' }
// r=2
// seen_words = { 'ab', 'bc' }
// starting_indices = [0]
// seen_words = { 'bc' }
// l=2
// r=4
// l=6, seen_words = {}
// r=6

// Submit Error
// CE: use of undeclared identifier 's_length'
// WA: word can be repeated
// CE: error: use of undeclared identifier 'required_word_count'
// WA: forgot to reset current_word_count when the current word is not in required words
// CE: required_words 原本傳進去是 const，比較 seen_words[current] > required_words[current] 時會報錯