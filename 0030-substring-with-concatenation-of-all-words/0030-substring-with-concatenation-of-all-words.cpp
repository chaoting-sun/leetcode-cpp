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
    void findStartingIndices(const string& s, unordered_map<string, int>& required_words, int start, vector<int>& starting_indices, const int word_length, const int required_word_count) {
        int s_length = s.size();
        unordered_map<string, int> seen_words;
        int current_word_count = 0;
        int left = start;

        for (int right = start; right < s_length - 1; right += word_length) {
            string current = s.substr(right, word_length);
            if (!required_words.count(current)) {
                left = right + word_length;
                current_word_count = 0;
                seen_words.clear();
                continue;
            }

            seen_words[current]++;
            current_word_count++;

            while (seen_words[current] > required_words[current]) {
                string previous = s.substr(left, word_length);
                current_word_count--;
                seen_words[previous]--;
                left += word_length;
            }

            if (current_word_count == required_word_count) {
                starting_indices.push_back(left);
                string previous = s.substr(left, word_length);
                seen_words[previous]--;
                current_word_count--;
                left += word_length;
            }
        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_length = s.size();
        if (s_length == 0) return {};

        unordered_map<string, int> required_words;
        int required_word_count = 0;
        for (const string& word: words) {
            required_word_count++;
            required_words[word]++;
        }
        
        vector<int> starting_indices;
        int word_length = words[0].size();
        for (int i = 0; i < word_length; i++) {
            findStartingIndices(s, required_words, i, starting_indices, word_length, required_word_count);
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
