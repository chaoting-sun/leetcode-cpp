class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int numWords = words.size();
        if (n == 0 || numWords == 0) return {};

        unordered_map<string,int> wordCount;
        for (string& word: words) wordCount[word]++;
        vector<int> ans;

        int wordLength = words[0].size();
        for (int i = 0; i < wordLength; i++) {
            int start = i;
            unordered_map<string,int> currentCount;
            int numCurrentWords = 0;

            for (int end = i; end <= n - wordLength + 1; end += wordLength) {
                string word = s.substr(end, wordLength);
                // not exist -> search on the next block
                if (!wordCount.count(word)) {
                    start = end + wordLength;
                    currentCount.clear();
                    numCurrentWords = 0;
                    continue;
                }

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

// barfoothefoobarman
// ["foo","bar"]
// wordCount = { foo: 1, bar: 1 }
// numWords = 2
// wordLength = 3

// i=0
// currentCount
// numCurrentWords=0

// start=0, end=0
// word=bar
// currentCount = { bar: 1 }
// numCurrentWords = 1

// end=3
// word=foo
// currentCount = { bar: 1, foo: 1 }
// numCurrentWords = 2