class Solution {
public:
    // Intuition: The first method that comes to mind is searching from every index,
    // checking if there is a valid substring starting at that index. However, this
    // would repeatedly check the same words for cases like s = "aaaaa...aaa" with
    // words including "a". Since the problem specifies that all words are of the
    // same length, we know that the start index (start) will satisfy
    // 0 <= start % wl < wl, where wl is the word length. Therefore, we divide the
    // search into wl cases. For each case, we use a standard sliding window to
    // search for a valid substring. We use start and end to bound the current
    // substring under consideration. When we still need to find unmatched words,
    // we expand end. If a word occurs more times than expected, we shrink start.
    //
    // Approach: Sliding Window
    // Time: O(n*wl + nw*wl) (n = length of s; wl = word length; nw = number of words)
    // Space: O(wl * (# distinct words))

    // Approach: Sliding Window
    // Time: O(n*wl+nw*wl) (n = length of s; wl = word length; nw = number of words)
    // Space: O(wl*(# distinct words))

    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int numWords = words.size();
        if (n == 0 || numWords == 0) return {};

        unordered_map<string,int> wordCount;
        for (string& word: words) wordCount[word]++; // O(wl*nw)
        vector<int> ans;

        int wordLength = words[0].size();
        for (int i = 0; i < wordLength; i++) { // O(wl)
            int start = i;
            unordered_map<string,int> currentCount;
            int numCurrentWords = 0;

            for (int end = i; end <= n - wordLength + 1; end += wordLength) { // O(n/wl)
                string word = s.substr(end, wordLength); // O(wl)
                // not exist -> search on the next block
                if (!wordCount.count(word)) {
                    start = end + wordLength;
                    // reset and start from the next position
                    currentCount.clear();
                    numCurrentWords = 0;
                    continue;
                }

                // if adding the current word make the substring invalid
                // then modify the position of "start"
                while (currentCount[word] >= wordCount[word]) {
                    string firstWord = s.substr(start, wordLength);
                    currentCount[firstWord]--;
                    numCurrentWords--;
                    start += wordLength;
                }

                currentCount[word]++;
                if (currentCount[word] <= wordCount[word]) {
                    numCurrentWords++;
                }
                
                if (numCurrentWords == numWords) {
                    ans.push_back(start);
                }
            }
        }
        
        return ans;
    }
};
