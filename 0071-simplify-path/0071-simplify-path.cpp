class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string ans;
        vector<string> pathArray;
        stack<string> stk;

        int current = 0;
        while (current < n) {
            while (current < n && path[current] == '/') current++;
            if (current == n) break;
            int right = current;
            while (right < n && path[right] != '/') right++;
            pathArray.push_back(path.substr(current, right - current));
            current = right;
        }
        
        for (string symbol: pathArray) {
            if (symbol == "..") {
                if (!stk.empty()) stk.pop();
            } else if (symbol != ".") {
                stk.push(symbol);
            }
        }

        if (stk.empty()) return "/";

        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};