class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }

    string decode(string& s, int& i) {
        string ans = "";
        int repeatedTimes = 0;
        stack<char> stk;

        while (i < s.size()) {
            char ch = s[i];
            if (isdigit(ch)) {
                repeatedTimes = repeatedTimes * 10 + (ch - '0');
                i++;
            } else if (ch == '[') {
                i++;
                string res = decode(s, i);
                for (int j = 0; j < repeatedTimes; j++) ans += res;
                repeatedTimes = 0;
            } else if (ch == ']') {
                i++;
                break;
            } else {
                ans.push_back(ch);
                i++;
            }
        }
        return ans;
    }
};